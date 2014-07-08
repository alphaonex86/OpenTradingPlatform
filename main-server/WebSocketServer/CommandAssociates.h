#ifndef COMMANDASSOCIATES_H
#define COMMANDASSOCIATES_H
#include <QtCore>

/***************************************************************************************/

typedef struct
{
    QString szParam ;
    QString szValue ;
} stParam ;

class CCommandParams
{
protected:
    int m_nCmdId ;
    QList< stParam * > qlCmdParams ;
public:
    virtual void ReadParams ( QString szMsg ) ;
    /*virtual*/ QList< stParam * > & GetCommandParams( ) ;
};

class CSignUpCommandParams : public CCommandParams
{
public:
    void ReadParams ( QString szMsg ) ;
//    QList< stParam * > & GetCommandParams( ) ;
} ;

class CLoginCommandParams : public CCommandParams
{
    QString m_szUserId ;
    QString m_szPassword ;

public:
    void ReadParams ( QString szMsg ) ;
    //QList * GetCommandParams( ) ;
} ;

class CForgotPasswordCommandParams : public CCommandParams
{
public:
    void ReadParams ( QString szMsg ) ;
//    QList * GetCommandParams( ) ;
} ;

class CBitcoinAccountInfoCommandParams : public CCommandParams
{
public:
    void ReadParams ( QString szMsg ) ;
//    QList * GetCommandParams( ) ;
} ;

class CCredentialsCommandParams : public CCommandParams
{
public:
    void ReadParams ( QString szMsg ) ;
//    QList * GetCommandParams( ) ;
} ;

class CProfileAccountCommandParams : public CCommandParams
{
public:
    void ReadParams ( QString szMsg ) ;
//    QList * GetCommandParams( ) ;
} ;

/*****************************************************************************************/

class CCmdResult
{
    QString m_szResult ;
public:
    CCmdResult( ) ;
    virtual QString & GetCmdResult( ) ;
};

class CCommand
{
private:
    qint16 m_nCmdId ;
    QString m_szCmdName ;
    CCommandParams *m_pParams ;

public:
    CCommand() {}
    ~CCommand( ) ;
    void SetCommandInfo( ) ;
    void GetCommandInfo( ) ;
    CCommand & operator = ( CCommand &cmd ) ;
    CCommand ( CCommand &cmd ) ;
    CCommandParams ** GetCommandParams( ) ;
};

class CCmdMessage
{
protected:
    QString m_szBinaryMessage ;
public:
    CCmdMessage( QString szMsg = NULL ):m_szBinaryMessage ( szMsg ) {}
    virtual void ParseCommandParams( ) ;
    const QString & GetMessage( ) ;
};

class CSignUpCmdMessage : public CCmdMessage
{
public:
    CSignUpCmdMessage( QString szMsg = NULL ):CCmdMessage ( szMsg ) {}
    void ParseCommandParams( ) ;
};

class CLoginCmdMessage : public CCmdMessage
{
public:
    CLoginCmdMessage( QString szMsg = NULL ):CCmdMessage ( szMsg ) {}
    void ParseCommandParams( ) ;
};

class CForgotPasswordCmdMessage : public CCmdMessage
{
public:
    CForgotPasswordCmdMessage( QString szMsg = NULL ):CCmdMessage ( szMsg ) {}
    void ParseCommandParams( ) ;
};

class CBitcoinAccountInfoCmdMessage : public CCmdMessage
{
public:
    CBitcoinAccountInfoCmdMessage( QString szMsg = NULL ):CCmdMessage ( szMsg ) {}
    void ParseCommandParams( ) ;
};

class CCredentialsCmdMessage : public CCmdMessage
{
public:
    CCredentialsCmdMessage( QString szMsg = NULL ):CCmdMessage ( szMsg ) {}
    void ParseCommandParams( ) ;
};

class CProfileAccountCmdMessage : public CCmdMessage
{
public:
    CProfileAccountCmdMessage( QString szMsg = NULL ):CCmdMessage ( szMsg ) {}
    void ParseCommandParams( ) ;
};
#endif // COMMANDASSOCIATES_H
