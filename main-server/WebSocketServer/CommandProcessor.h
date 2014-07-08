#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include "CommandAssociates.h"

class CCommandProcessor
{
protected:
    //CCommand m_objCmd ;
    CCommand *m_pCmd ;
    CCmdResult m_objCmdResult ;
    QList< stParam * > m_lstParam ;
public:
    virtual void Process ( CCommand *pCmd = NULL ) ;
    virtual /*CCommand &*/void ParseCommand ( CCmdMessage *pMsg ) ;//CCommand can be removed during Refactoring Code
    virtual CCmdResult & GetCmdResult( ) ;
    virtual ~CCommandProcessor( ) ;
};

class CSignupProcessor : public CCommandProcessor
{
public:
    CSignupProcessor( ) ; //: CCommandProcessor() {}

    void Process( CCommand *pCmd = NULL ) ;
    /*CCommand &*/void ParseCommand ( CCmdMessage *pMsg ) ;
    CCmdResult & GetCmdResult( ) ;
};
class CLoginProcessor: public CCommandProcessor
{
public:
    void Process( CCommand *pCmd = NULL ) ;
    void ParseCommand ( CCmdMessage *pMsg ) ;
    CCmdResult & GetCmdResult( ) ;
};

class CForgotPasswordProcessor : public CCommandProcessor
{
public:
    CForgotPasswordProcessor( ) ;//: CCommandProcessor() ; //{}

    void Process( CCommand *pCmd = NULL ) ;
    void ParseCommand ( CCmdMessage *pMsg ) ;
    CCmdResult & GetCmdResult( ) ;
};

class CBitcoinAccountInfoProcessor : public CCommandProcessor
{
public:
    CBitcoinAccountInfoProcessor( ) ; //: CCommandProcessor( ) {}

    void Process( CCommand *pCmd = NULL ) ;
    void ParseCommand ( CCmdMessage *pMsg ) ;
    CCmdResult & GetCmdResult( ) ;
} ;

class CCredentialsProcessor : public CCommandProcessor
{
public:
    CCredentialsProcessor( ) ; //: CCommandProcessor( ) {}
    void Process( CCommand *pCmd = NULL ) ;
    void ParseCommand ( CCmdMessage *pMsg ) ;
    CCmdResult & GetCmdResult( ) ;
};

class CProfileAccountProcessor : public CCommandProcessor
{
public:
    CProfileAccountProcessor( ) ; //: CCommandProcessor() {}

    void Process( CCommand *pCmd = NULL ) ;
    void ParseCommand ( CCmdMessage *pMsg ) ;
    CCmdResult & GetCmdResult( ) ;
};


#endif // COMMANDPROCESSOR_H
