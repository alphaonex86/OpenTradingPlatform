#include "CommandProcessor.h"
#include "CommandAssociates.h"
#include "sqlhandler.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"

CCommandProcessor::~CCommandProcessor( )
{
    if ( NULL != m_pCmd )
    {
        delete m_pCmd ;
        m_pCmd = NULL ;
    }
}

void CCommandProcessor::Process ( CCommand *pCmd )
{
    qDebug( ) << "Processing the Command" ;
}

void CCommandProcessor::ParseCommand ( CCmdMessage *pMsg )
{
    qDebug( ) << "Parsing the Command Message received." ;

    CCommand *pCmd = new CCommand ;
    //Needs to be Filled in.

//    return *pCmd ;
}

CCmdResult & CCommandProcessor::GetCmdResult( )
{
    return m_objCmdResult ;
}

CSignupProcessor::CSignupProcessor( ) : CCommandProcessor() {}

void CSignupProcessor::Process( CCommand *pCmd )
{

}

void CSignupProcessor::ParseCommand ( CCmdMessage *pMsg )
{
    CCommand *pCmd = new CCommand ;
    CCommandParams **pCmdParams = pCmd ->GetCommandParams( ) ;

//    return *pCmd ;
}

CCmdResult & CSignupProcessor::GetCmdResult( )
{
    return m_objCmdResult ;
}

void CLoginProcessor::Process( CCommand *pCmd )
{
    //Verify the Params from the Database
    QSqlDatabase * pSqlDB = SqlHandler::GetDatabaseHandler( ) ;
    if ( pSqlDB ->isOpen( ) )
    {
        QString sql = "Select * from account where ac_number=" ;
        stParam par = *m_lstParam[1] ;
        sql += par.szValue ;
        sql += " or email=" ;
        sql += par.szValue ;
        sql += " ;" ;

        QSqlQuery query = pSqlDB ->exec( sql ) ;

        //query.

        int fieldNoAcc = query.record( ).indexOf( "ac_number" ) ;
        int fieldNoemail = query.record( ).indexOf ( "email" ) ;
        int fieldNoPwd = query.record( ).indexOf ( "pwd_enc" ) ;
        while (query.next()) {
            QString Account = query.value(fieldNoAcc).toString();
            QString email = query.value(fieldNoemail).toString();
            QString pwd = query.value(fieldNoPwd).toString();

            if ( Account.isEmpty( ) && email.isEmpty( ) )
            {
                qDebug( ) << "Not Found" ;
//            doSomething(country);
            }
            else
            {
                //Verifying the Account or the email
                if ( m_lstParam[1]->szValue == Account || m_lstParam[1] ->szValue == email)
                {
                    //Verifying the Password
                    if ( m_lstParam[2] ->szValue == pwd )
                    {
                        qDebug( ) << "Valid User" ;
                        //Frame Valid User Reply
                    }
                    else
                    {
                        //Frame Invalid User Reply
                        qDebug( ) << "Invalid User" ;
                    }
                }

            }
        }

    }
    //If Matched, Frame the Reply and Send the Reply to the Browser or Client.
}

void CLoginProcessor::ParseCommand ( CCmdMessage *pMsg )
{
    //m_pCmd = new CCommand ;
    CCommandParams *pCmdParams = new CLoginCommandParams ; //m_pCmd ->GetCommandParams( ) ;
    pCmdParams ->ReadParams ( pMsg ->GetMessage( ) ) ;

    /*QList< stParam * >*/ m_lstParam = pCmdParams ->GetCommandParams( ) ;
    QList< stParam * >::iterator iter ;

    for ( iter = m_lstParam.begin( ) ; iter != m_lstParam.end( ) ; iter++ )
    {
        qDebug( ) << ( *iter ) ->szParam << " => " << ( *iter ) ->szValue ;
    }

//    QJsonValue jVal ;
////    int msgId = 1801 ;
//    QJsonParseError err ;
//    QByteArray qArr ;

//    qArr = pMsg ->GetMessage().toUtf8( ) ;
//    QJsonDocument jDoc = QJsonDocument::fromJson ( qArr, &err ) ;

//    if ( jDoc.isObject( ) )
//    {
//        QJsonObject jObj ;
//        jObj = jDoc.object( ) ;

//        QJsonObject::iterator itr = jObj.find ( "name" ) ;
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

//    return NULL/**this*/ ;
}

CCmdResult & CLoginProcessor::GetCmdResult( )
{
    return m_objCmdResult ;
}


CForgotPasswordProcessor::CForgotPasswordProcessor( ) : CCommandProcessor() {}

void CForgotPasswordProcessor::Process( CCommand *pCmd )
{

}

void CForgotPasswordProcessor::ParseCommand ( CCmdMessage *pMsg )
{
    CCommand *pCmd = new CCommand ;

//    return *pCmd ;
}

CCmdResult & CForgotPasswordProcessor::GetCmdResult( )
{
    return m_objCmdResult ;
}


CBitcoinAccountInfoProcessor::CBitcoinAccountInfoProcessor( ) : CCommandProcessor( ) {}

void CBitcoinAccountInfoProcessor::Process( CCommand *pCmd )
{

}

void CBitcoinAccountInfoProcessor::ParseCommand ( CCmdMessage *pMsg )
{
    CCommand *pCmd = new CCommand ;

//    return *pCmd ;
}

CCmdResult & CBitcoinAccountInfoProcessor::GetCmdResult( )
{
    return m_objCmdResult ;
}

CCredentialsProcessor::CCredentialsProcessor( ) : CCommandProcessor( ) {}

void CCredentialsProcessor::Process( CCommand *pCmd )
{

}

void CCredentialsProcessor::ParseCommand ( CCmdMessage *pMsg )
{
    CCommand *pCmd = new CCommand ;

//    return *pCmd ;
}

CCmdResult & CCredentialsProcessor::GetCmdResult( )
{
    return m_objCmdResult ;
}

CProfileAccountProcessor::CProfileAccountProcessor( ) : CCommandProcessor() {}

void CProfileAccountProcessor::Process( CCommand *pCmd )
{

}

void CProfileAccountProcessor::ParseCommand ( CCmdMessage *pMsg )
{
    CCommand *pCmd = new CCommand ;

//    return *pCmd ;
}

CCmdResult & CProfileAccountProcessor::GetCmdResult( )
{
    return m_objCmdResult ;
}

