#include "CommandAssociates.h"
#include <QJsonDocument>

void CCommandParams::ReadParams ( QString szMsg )
{

}

QList< stParam * > & CCommandParams::GetCommandParams( )
{
    return qlCmdParams ;
}

void CSignUpCommandParams::ReadParams ( QString szMsg )
{

}

void CLoginCommandParams::ReadParams ( QString szMsg )
{
    QJsonValue jVal ;
//    int msgId = 1801 ;
    QJsonParseError err ;
    QByteArray qArr ;

    qArr = szMsg.toUtf8( ) ;
    QJsonDocument jDoc = QJsonDocument::fromJson ( qArr, &err ) ;

    if ( jDoc.isObject( ) )
    {
        QJsonObject jObj ;
        jObj = jDoc.object( ) ;

        QJsonObject::iterator itr = jObj.begin() ;//find ( "name" ) ;

        for ( itr = jObj.begin(); itr != jObj.end( ) ; itr++ )
        {
            stParam *pParam = new stParam ;
            pParam ->szParam = itr.key( ) ;
            jVal = itr.value( ) ;

            pParam ->szValue = jVal.toString( ) ;

            qlCmdParams.push_back( pParam ) ;
        }
    }

//        if ( itr == jObj.end( ) )
//        {
//            // object not found.
//        }
//        else if ( jObj.contains( "name" ) )
//        {
//            qDebug( ) << "Contains the Name String in JSON Object String" ;
//            jVal = itr.value( ) ;

//            qDebug( ) << jVal ;
//        }
//    }

//    m_szUserId = jVal.toString( )/*1801*/ ;
//    qDebug << "Got the User Id: " << m_szUserId << endl ;
}

void CForgotPasswordCommandParams::ReadParams ( QString szMsg )
{

}

void CBitcoinAccountInfoCommandParams::ReadParams ( QString szMsg )
{

}

void CCredentialsCommandParams::ReadParams ( QString szMsg )
{

}

void CProfileAccountCommandParams::ReadParams ( QString szMsg )
{

}

//CCommand::CCommand() {}

CCommand::~CCommand( )
{
    if ( NULL != m_pParams )
    {
        delete m_pParams ;
        m_pParams = NULL ;
    }
}

void CCommand::SetCommandInfo( )
{

}

CCommand::CCommand ( CCommand &cmd )
{
    m_nCmdId = cmd.m_nCmdId ;
    m_szCmdName = cmd.m_szCmdName ;
    //pParams = new CCommandParams ;
    //pParams = cmd.pParams ;
//    return *this ;
}

CCommand & CCommand::operator = ( CCommand &cmd )
{
    m_nCmdId = cmd.m_nCmdId ;
    m_szCmdName = cmd.m_szCmdName ;
    //pParams = new CCommandParams ;
    //pParams = cmd.pParams ;
    return *this ;
}

CCommandParams ** CCommand::GetCommandParams( )
{
    return &m_pParams ;
}

CCmdResult::CCmdResult( ): m_szResult ( "Processed Successfully" )
{

}

QString & CCmdResult::GetCmdResult( )
{
    return m_szResult ;
}


//CCmdMessage::CCmdMessage() {}

const QString & CCmdMessage::GetMessage( )
{
    return m_szBinaryMessage ;
}

void CCmdMessage::ParseCommandParams( )
{

}

void CSignUpCmdMessage::ParseCommandParams( )
{

}

void CLoginCmdMessage::ParseCommandParams( )
{
    //Read the Params - Mail or BC Account Id and Password

}

void CForgotPasswordCmdMessage::ParseCommandParams( )
{

}

void CBitcoinAccountInfoCmdMessage::ParseCommandParams( )
{

}

void CCredentialsCmdMessage::ParseCommandParams( )
{

}

void CProfileAccountCmdMessage::ParseCommandParams( )
{

}
