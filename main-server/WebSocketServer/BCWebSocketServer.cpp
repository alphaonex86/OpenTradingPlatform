/****************************************************************************
**
** Copyright (C) 2014 Kurt Pattyn <pattyn.kurt@gmail.com>.
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtWebSockets module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "BCWebSocketServer.h"
#include "QtWebSockets/QWebSocketServer"
#include "QtWebSockets/QWebSocket"
#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtNetwork/QSslCertificate>
#include <QtNetwork/QSslKey>
//#include <./localhost.cert>

QT_USE_NAMESPACE

//! [constructor]
BCWebSocketServer::BCWebSocketServer(quint16 port, QObject *parent) :
    QObject(parent),
    m_pWebSocketServer(Q_NULLPTR),
    m_clients()
{
    m_pWebSocketServer = new QWebSocketServer(QStringLiteral("Bitcoin Exchange Server"),
                                              QWebSocketServer::NonSecureMode, //**** To be Changed after setting up OpenSSL
                                              this);
    QSslConfiguration sslConfiguration;
    QFile certFile(QStringLiteral("./localhost.cert"));
    QFile keyFile(QStringLiteral("./localhost.key"));
    /*if ( */
    certFile.open(stderr, QIODevice::ReadOnly | QIODevice::Text ) ; //&&
    keyFile.open(stderr, QIODevice::ReadOnly | QIODevice::Text) ; // )
    {
        QSslCertificate certificate(&certFile, QSsl::Pem);
        QSslKey sslKey(&keyFile, QSsl::Rsa, QSsl::Pem);
        certFile.close();
        keyFile.close();
        sslConfiguration.setPeerVerifyMode(QSslSocket::VerifyNone);
        sslConfiguration.setLocalCertificate(certificate);
        sslConfiguration.setPrivateKey(sslKey);
        sslConfiguration.setProtocol(QSsl::TlsV1SslV3);
        m_pWebSocketServer->setSslConfiguration(sslConfiguration);

        if (m_pWebSocketServer->listen(QHostAddress::Any, port))
        {
            qDebug() << "Bitcoin Exchange Server listening on port" << port;
            connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                    this, &BCWebSocketServer::onNewConnection);
            connect(m_pWebSocketServer, &QWebSocketServer::sslErrors,
                    this, &BCWebSocketServer::onSslErrors);
        }

        _logged = false;
        _lang = NULL;

        this->data.rank = 0;
    }
}
//! [constructor]

BCWebSocketServer::~BCWebSocketServer()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

bool BCWebSocketServer::isLogged()
{
    return _logged;
}

void BCWebSocketServer::logIn()
{
    // temporary
    _logged = true;
}

void BCWebSocketServer::logOut()
{
    // temporary
    _logged = false;
}

TranslationsLang* BCWebSocketServer::getLang()
{
    return _lang;
}

void BCWebSocketServer::setLang(TranslationsLang* lang)
{
    _lang = lang;
}

//! [onNewConnection]
void BCWebSocketServer::onNewConnection()
{
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

    qDebug() << "Client connected:" << pSocket->peerName() << pSocket->origin();

    connect(pSocket, &QWebSocket::textMessageReceived, this, &BCWebSocketServer::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived,
            this, &BCWebSocketServer::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &BCWebSocketServer::socketDisconnected);
    //connect(pSocket, &QWebSocket::pong, this, &SslEchoServer::processPong);

    m_clients << pSocket;
}
//! [onNewConnection]

//! [processTextMessage]
void BCWebSocketServer::processTextMessage(QString message)
{
    qDebug() << message ;
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
    {
        pClient->sendTextMessage(message);
    }
}
//! [processTextMessage]

//! [processBinaryMessage]
void BCWebSocketServer::processBinaryMessage(QByteArray message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
    {
        pClient->sendBinaryMessage(message);
    }
}
//! [processBinaryMessage]

//! [socketDisconnected]
void BCWebSocketServer::socketDisconnected()
{
    qDebug() << "Client disconnected";
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
    {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}

void BCWebSocketServer::onSslErrors(const QList<QSslError> &)
{
    qDebug() << "Ssl errors occurred";
}
//! [socketDisconnected]

bool BCWebSocketServer::hasRight(Right r)
{
    return r <= this->data.rank;
}

