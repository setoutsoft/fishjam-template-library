#ifndef FTL_WINDOW_HPP
#define FTL_WINDOW_HPP
#pragma once

#ifdef USE_EXPORT
#  include "ftlwindow.h"
#endif

#include <prsht.h>

namespace FTL
{
    class CFDummyMsgInfo
    {
    public:
    };

    CFMessageInfo::CFMessageInfo(UINT msg, WPARAM wParam, LPARAM lParam) 
        : CFConvertInfoT<CFMessageInfo,UINT>(msg)
        , m_wParam(wParam)
        , m_lParam(lParam)
    {
    }

#define GET_MESSAGE_INFO_ENTRY(msg) GET_MESSAGE_INFO_ENTRY_EX( msg, CFDummyMsgInfo )

#define GET_MESSAGE_INFO_ENTRY_EX(msg, classDumpInfo ) HANDLE_CASE_TO_STRING(m_bufInfo,_countof(m_bufInfo), msg)

    LPCTSTR CFMessageInfo::ConvertInfo()
    {
        if (NULL == m_bufInfo[0])
        {
            switch(m_Info)
            {
                GET_MESSAGE_INFO_ENTRY(WM_CREATE);
                GET_MESSAGE_INFO_ENTRY(WM_DESTROY);  //�رմ���ʱ,�����������,����PostQuitMessage,������̻�������(ֻ��û�д���)
                GET_MESSAGE_INFO_ENTRY(WM_MOVE);
                GET_MESSAGE_INFO_ENTRY(WM_SIZE);
                GET_MESSAGE_INFO_ENTRY(WM_ACTIVATE); //���ڱ������ʧȥ����״̬, �����ڲ鿴�����Ƿ���С������ǰһ����
                GET_MESSAGE_INFO_ENTRY(WM_SETFOCUS);
                GET_MESSAGE_INFO_ENTRY(WM_KILLFOCUS);
                GET_MESSAGE_INFO_ENTRY(WM_ENABLE); //����ֹ�򼤻�ʱ
                GET_MESSAGE_INFO_ENTRY(WM_SETREDRAW); //���ô����Ƿ����ػ� 
                GET_MESSAGE_INFO_ENTRY(WM_SETTEXT);
                GET_MESSAGE_INFO_ENTRY(WM_GETTEXT);
                GET_MESSAGE_INFO_ENTRY(WM_GETTEXTLENGTH); //�õ���һ�������йص��ı��ĳ��ȣ����������ַ���
                GET_MESSAGE_INFO_ENTRY(WM_PAINT);
                GET_MESSAGE_INFO_ENTRY(WM_CLOSE);
#ifndef _WIN32_WCE
                GET_MESSAGE_INFO_ENTRY(WM_QUERYENDSESSION); //���û�ѡ������Ի��������Լ�����ExitWindows����
                GET_MESSAGE_INFO_ENTRY(WM_QUERYOPEN);     //���û����ڻָ���ǰ�Ĵ�Сλ��ʱ���Ѵ���Ϣ���͸�ĳ��ͼ��
                GET_MESSAGE_INFO_ENTRY(WM_ENDSESSION);    //��ϵͳ���̷���WM_QUERYENDSESSION��Ϣ�󣬴���Ϣ���͸�Ӧ�ó���֪ͨ���Ի��Ƿ����
#endif
                GET_MESSAGE_INFO_ENTRY(WM_QUIT);
                GET_MESSAGE_INFO_ENTRY(WM_ERASEBKGND); //�����ڱ������뱻����ʱ�����ڴ��ڸı��Сʱ��
                GET_MESSAGE_INFO_ENTRY(WM_SYSCOLORCHANGE);    //��ϵͳ��ɫ�ı�ʱ�����ʹ���Ϣ�����ж�������
                GET_MESSAGE_INFO_ENTRY(WM_SHOWWINDOW);

#ifndef WM_CTLCOLOR
#  define WM_CTLCOLOR                             0x0019
#endif
                //�Ӵ������ڻ��ƿͻ���֮ǰ�����䷢�͸������ڣ�ί�и�����Ϊ�Լ�׼��һ����ˢ��ͬʱ�����ڣ���Ի���Ҳ���Լ����͸���Ϣ(Ϊʲô��)
                GET_MESSAGE_INFO_ENTRY(WM_CTLCOLOR);  

                GET_MESSAGE_INFO_ENTRY(WM_WININICHANGE);
                GET_MESSAGE_INFO_ENTRY(WM_DEVMODECHANGE);
                GET_MESSAGE_INFO_ENTRY(WM_ACTIVATEAPP);//������һApp�Ĵ��彫����ʱ
                GET_MESSAGE_INFO_ENTRY(WM_FONTCHANGE);    //��ϵͳ��������Դ��仯ʱ���ʹ���Ϣ�����ж�������
                GET_MESSAGE_INFO_ENTRY(WM_TIMECHANGE);    //��ϵͳ��ʱ��仯ʱ���ʹ���Ϣ�����ж�������
                GET_MESSAGE_INFO_ENTRY(WM_CANCELMODE);    //ȡ��ϵͳģʽʱ
                GET_MESSAGE_INFO_ENTRY(WM_SETCURSOR);     //��������������ĳ���������ƶ����������û�б�����ʱ���ͷ���Ϣ��ĳ������
                GET_MESSAGE_INFO_ENTRY(WM_MOUSEACTIVATE);
                GET_MESSAGE_INFO_ENTRY(WM_CHILDACTIVATE); //�ʹ���Ϣ��MDI�Ӵ��ڵ��û�����˴��ڵı��������򵱴��ڱ�����ƶ����ı��С
                GET_MESSAGE_INFO_ENTRY(WM_QUEUESYNC);     //����Ϣ�ɻ��ڼ������"ѵ��?"�����ͣ�ͨ�� WH_JOURNALPALYBACK ��hook���������û�������Ϣ
                GET_MESSAGE_INFO_ENTRY(WM_GETMINMAXINFO); //����Ϣ���͸����ڵ�����Ҫ�ı��С��λ��

                GET_MESSAGE_INFO_ENTRY(WM_PAINTICON);     //���͸���С�����ڵ���ͼ�꽫Ҫ���ػ�
                GET_MESSAGE_INFO_ENTRY(WM_ICONERASEBKGND);//����Ϣ���͸�ĳ����С�����ڣ��������ڻ�ͼ��ǰ���ı������뱻�ػ�
                GET_MESSAGE_INFO_ENTRY(WM_NEXTDLGCTL);    //����Ϣ���͸�ĳ����С�����ڣ��������ڻ�ͼ��ǰ���ı������뱻�ػ�
                GET_MESSAGE_INFO_ENTRY(WM_SPOOLERSTATUS); //ÿ����ӡ�����ж����ӻ����һ����ҵʱ��������Ϣ
                GET_MESSAGE_INFO_ENTRY(WM_DRAWITEM);
                GET_MESSAGE_INFO_ENTRY(WM_MEASUREITEM);
                GET_MESSAGE_INFO_ENTRY(WM_DELETEITEM);
                GET_MESSAGE_INFO_ENTRY(WM_VKEYTOITEM);    //��һ��LBS_WANTKEYBOARDINPUT���ķ�������������������ӦWM_KEYDOWN��Ϣ
                GET_MESSAGE_INFO_ENTRY(WM_CHARTOITEM);    //��һ��LBS_WANTKEYBOARDINPUT�����б����͸���������������ӦWM_CHAR��Ϣ
                GET_MESSAGE_INFO_ENTRY(WM_SETFONT);
                GET_MESSAGE_INFO_ENTRY(WM_GETFONT);
                GET_MESSAGE_INFO_ENTRY(WM_SETHOTKEY);     //Ӧ�ó����ʹ���Ϣ��һ��������һ���ȼ������
                GET_MESSAGE_INFO_ENTRY(WM_GETHOTKEY);     //Ӧ�ó����ʹ���Ϣ���ж��ȼ���ĳ�������Ƿ��й���
                GET_MESSAGE_INFO_ENTRY(WM_QUERYDRAGICON); //�͸���С�����ڣ����˴��ڽ�Ҫ���ϷŶ���������û�ж���ͼ�꣬Ӧ�ó����ܷ���һ��ͼ�����ľ����
                //���û��Ϸ�ͼ��ʱϵͳ��ʾ���ͼ�����
                GET_MESSAGE_INFO_ENTRY(WM_COMPAREITEM);   //���ʹ���Ϣ���ж�combobox��listbox�����ӵ�������λ��
#if(WINVER >= 0x0500)
                GET_MESSAGE_INFO_ENTRY(WM_GETOBJECT);
#endif
                GET_MESSAGE_INFO_ENTRY(WM_COMPACTING);    //��ʾ�ڴ��Ѿ�������
                GET_MESSAGE_INFO_ENTRY(WM_COMMNOTIFY);
                GET_MESSAGE_INFO_ENTRY(WM_WINDOWPOSCHANGING);
                GET_MESSAGE_INFO_ENTRY(WM_WINDOWPOSCHANGED);
                GET_MESSAGE_INFO_ENTRY(WM_POWER);         //��ϵͳ��Ҫ������ͣ״̬ʱ���ʹ���Ϣ
                GET_MESSAGE_INFO_ENTRY(WM_COPYDATA);
                GET_MESSAGE_INFO_ENTRY(WM_CANCELJOURNAL); //��ĳ���û�ȡ��������־����״̬���ύ����Ϣ������
#if(WINVER >= 0x0400)
            case WM_NOTIFY:
                {
                    //GET_MESSAGE_INFO_ENTRY(WM_NOTIFY);
                    StringCchCopy(m_bufInfo,_countof(m_bufInfo),TEXT("WM_NOTIFY,"));
                    int len = lstrlen(m_bufInfo);
                    int nIdCtrl = (int)m_wParam;
                    LPNMHDR pNmHdr = (LPNMHDR)m_lParam;
                    StringCchPrintf(m_bufInfo + len, _countof(m_bufInfo) - len, 
                        TEXT("id=%d,code=%s"), nIdCtrl, CFWinUtil::GetNotifyCodeString(pNmHdr->code));
                    break;
                }

                GET_MESSAGE_INFO_ENTRY(WM_INPUTLANGCHANGEREQUEST);    //���û�ѡ��ĳ���������ԣ����������Ե��ȼ��ı�
                GET_MESSAGE_INFO_ENTRY(WM_INPUTLANGCHANGE);   //��ƽ̨�ֳ��Ѿ����ı���ʹ���Ϣ����Ӱ����������
                GET_MESSAGE_INFO_ENTRY(WM_TCARD);         //�������Ѿ���ʼ��windows��������ʱ���ʹ���Ϣ��Ӧ�ó���
                GET_MESSAGE_INFO_ENTRY(WM_HELP);          //����Ϣ��ʾ�û�������F1�����ĳ���˵��Ǽ���ģ��ͷ��ʹ���Ϣ���˴��ڹ����Ĳ˵���
                //  ����ͷ��͸��н���Ĵ��ڣ������ǰ��û�н��㣬�ͰѴ���Ϣ���͸���ǰ����Ĵ���
                GET_MESSAGE_INFO_ENTRY(WM_USERCHANGED);   //���û��Ѿ�������˳����ʹ���Ϣ�����еĴ��ڣ����û�������˳�ʱϵͳ�����û��ľ���
                //  ������Ϣ�����û���������ʱϵͳ���Ϸ��ʹ���Ϣ
                GET_MESSAGE_INFO_ENTRY(WM_NOTIFYFORMAT);  //ͨ������Ϣ���жϿؼ���ʹ��ANSI����UNICODE�ṹ
                GET_MESSAGE_INFO_ENTRY(WM_CONTEXTMENU);   //���û�ĳ�������е����һ���Ҽ��ͷ��ʹ���Ϣ���������
                GET_MESSAGE_INFO_ENTRY(WM_STYLECHANGING); //������SETWINDOWLONG���� ��Ҫ�ı� һ������ ���ڵķ��ʱ���ʹ���Ϣ���Ǹ�����
                GET_MESSAGE_INFO_ENTRY(WM_STYLECHANGED);  //������SETWINDOWLONG���� �ı� һ���������ڵķ����ʹ���Ϣ���Ǹ�����
                GET_MESSAGE_INFO_ENTRY(WM_DISPLAYCHANGE); //����ʾ���ķֱ��ʸı���ʹ���Ϣ�����еĴ���
                GET_MESSAGE_INFO_ENTRY(WM_GETICON);
                GET_MESSAGE_INFO_ENTRY(WM_SETICON);
#endif
                GET_MESSAGE_INFO_ENTRY(WM_NCCREATE);      //��ĳ�����ڵ�һ�α�����ʱ������Ϣ��WM_CREATE��Ϣ����ǰ����
                GET_MESSAGE_INFO_ENTRY(WM_NCDESTROY);     //����Ϣ֪ͨĳ�����ڣ��ǿͻ�����������
                
                //��Ҫ���㴰�ڿͻ����Ĵ�С��λ��ʱ���ͣ�ͨ����������Ϣ�������ڴ��ڴ�С��λ�øı�ʱ���ƿͻ���������     
                GET_MESSAGE_INFO_ENTRY(WM_NCCALCSIZE);    
                GET_MESSAGE_INFO_ENTRY(WM_NCHITTEST);
                GET_MESSAGE_INFO_ENTRY(WM_NCPAINT);       //�����ʹ���Ϣ��ĳ�����ڵ��������ڣ��Ŀ�ܱ��뱻����ʱ
                GET_MESSAGE_INFO_ENTRY(WM_NCACTIVATE);    //����Ϣ���͸�ĳ������ �������ķǿͻ�����Ҫ���ı�����ʾ�Ǽ���ǷǼ���״̬
                GET_MESSAGE_INFO_ENTRY(WM_GETDLGCODE);    //���ʹ���Ϣ��ĳ����Ի����������Ŀؼ���widdows���Ʒ�λ����TAB��ʹ�������˿ؼ�
                //  ͨ����ӦWM_GETDLGCODE��Ϣ��Ӧ�ó�����԰�������һ�����������ؼ����ܴ�����
#ifndef _WIN32_WCE
                GET_MESSAGE_INFO_ENTRY(WM_SYNCPAINT);
#endif
                GET_MESSAGE_INFO_ENTRY(WM_NCMOUSEMOVE);   //�ǿͻ������ƶ�ʱ���ʹ���Ϣ���������
                GET_MESSAGE_INFO_ENTRY(WM_NCLBUTTONDOWN);
                GET_MESSAGE_INFO_ENTRY(WM_NCLBUTTONUP);
                GET_MESSAGE_INFO_ENTRY(WM_NCLBUTTONDBLCLK);
                GET_MESSAGE_INFO_ENTRY(WM_NCRBUTTONDOWN);
                GET_MESSAGE_INFO_ENTRY(WM_NCRBUTTONUP);
                GET_MESSAGE_INFO_ENTRY(WM_NCRBUTTONDBLCLK);
                GET_MESSAGE_INFO_ENTRY(WM_NCMBUTTONDOWN);
                GET_MESSAGE_INFO_ENTRY(WM_NCMBUTTONUP);
                GET_MESSAGE_INFO_ENTRY(WM_NCMBUTTONDBLCLK);

#if(_WIN32_WINNT >= 0x0500)
                GET_MESSAGE_INFO_ENTRY(WM_NCXBUTTONDOWN);
                GET_MESSAGE_INFO_ENTRY(WM_NCXBUTTONUP);
                GET_MESSAGE_INFO_ENTRY(WM_NCXBUTTONDBLCLK);
#endif

#if(_WIN32_WINNT >= 0x0501)
                GET_MESSAGE_INFO_ENTRY(WM_INPUT);
#endif
                //GET_MESSAGE_INFO_ENTRY(WM_KEYFIRST);
                GET_MESSAGE_INFO_ENTRY(WM_KEYDOWN);
                GET_MESSAGE_INFO_ENTRY(WM_KEYUP);
                GET_MESSAGE_INFO_ENTRY(WM_CHAR);
                GET_MESSAGE_INFO_ENTRY(WM_DEADCHAR); //���� translatemessage ��������WM_KEYUP��Ϣʱ���ʹ���Ϣ��ӵ�н���Ĵ���
                GET_MESSAGE_INFO_ENTRY(WM_SYSKEYDOWN);    //���û���סALT��ͬʱ����������ʱ�ύ����Ϣ��ӵ�н���Ĵ���
                GET_MESSAGE_INFO_ENTRY(WM_SYSKEYUP);      //���û��ͷ�һ����ͬʱALT ��������ʱ�ύ����Ϣ��ӵ�н���Ĵ���
                GET_MESSAGE_INFO_ENTRY(WM_SYSCHAR);       //��WM_SYSKEYDOWN��Ϣ��TRANSLATEMESSAGE����������ύ����Ϣ��ӵ�н���Ĵ�
                GET_MESSAGE_INFO_ENTRY(WM_SYSDEADCHAR);   //
#if(_WIN32_WINNT >= 0x0501)
                GET_MESSAGE_INFO_ENTRY(WM_UNICHAR);
                //GET_MESSAGE_INFO_ENTRY(WM_KEYLAST);
                GET_MESSAGE_INFO_ENTRY(UNICODE_NOCHAR);
#else
                GET_MESSAGE_INFO_ENTRY(WM_KEYLAST);
#endif

#if(WINVER >= 0x0400)
#endif
                GET_MESSAGE_INFO_ENTRY(WM_IME_STARTCOMPOSITION);
                GET_MESSAGE_INFO_ENTRY(WM_IME_ENDCOMPOSITION);
                GET_MESSAGE_INFO_ENTRY(WM_IME_COMPOSITION);
                //GET_MESSAGE_INFO_ENTRY(WM_IME_KEYLAST);

                GET_MESSAGE_INFO_ENTRY(WM_INITDIALOG); //��һ���Ի��������ʾǰ���ʹ���Ϣ������ͨ���ô���Ϣ��ʼ���ؼ���ִ����������
                GET_MESSAGE_INFO_ENTRY(WM_COMMAND);

                //������������Ļ��������ʾ���ڵ�ģʽ(SC_SCREENSAVE/SC_MONITORPOWER),����0
                GET_MESSAGE_INFO_ENTRY(WM_SYSCOMMAND);    //���û�ѡ�񴰿ڲ˵���һ��������û�ѡ����󻯻���С��ʱ�Ǹ����ڻ��յ�����Ϣ

                GET_MESSAGE_INFO_ENTRY(WM_TIMER);     //�����˶�ʱ���¼�
                GET_MESSAGE_INFO_ENTRY(WM_HSCROLL);   //ˮƽ����������һ�������¼�
                GET_MESSAGE_INFO_ENTRY(WM_VSCROLL);   //��ֱ����������һ�������¼�
                GET_MESSAGE_INFO_ENTRY(WM_INITMENU);  //��һ���˵���Ҫ������ʱ���ʹ���Ϣ�����������û��˵����е�ĳ�����ĳ���˵�����
                //  ��������������ʾǰ���Ĳ˵�
                GET_MESSAGE_INFO_ENTRY(WM_INITMENUPOPUP);
#ifdef WM_SYSTIMER
#error Already define WM_SYSTIMER
#endif 

#ifndef WM_SYSTIMER
#define WM_SYSTIMER 0x0118
                GET_MESSAGE_INFO_ENTRY(WM_SYSTIMER);  //UnDocument Message
#endif

                GET_MESSAGE_INFO_ENTRY(WM_MENUSELECT); //���û�ѡ��һ���˵���ʱ���ʹ���Ϣ���˵��������ߣ�һ���Ǵ��ڣ�
                GET_MESSAGE_INFO_ENTRY(WM_MENUCHAR);  //���˵��ѱ������û�������ĳ��������ͬ�ڼ��ټ��������ʹ���Ϣ���˵���������
                GET_MESSAGE_INFO_ENTRY(WM_ENTERIDLE); //��һ��ģ̬�Ի����˵��������״̬ʱ(������һ��������ǰ����Ϣ��û����Ϣ�����ж��еȴ�)���ʹ���Ϣ�����������ߣ�
#if(WINVER >= 0x0500)
                GET_MESSAGE_INFO_ENTRY(WM_MENURBUTTONUP);
                GET_MESSAGE_INFO_ENTRY(WM_MENUDRAG);
                GET_MESSAGE_INFO_ENTRY(WM_MENUGETOBJECT);
                GET_MESSAGE_INFO_ENTRY(WM_UNINITMENUPOPUP);
                GET_MESSAGE_INFO_ENTRY(WM_MENUCOMMAND);
#  if(_WIN32_WINNT >= 0x0500)
                GET_MESSAGE_INFO_ENTRY(WM_CHANGEUISTATE);
                GET_MESSAGE_INFO_ENTRY(WM_UPDATEUISTATE);
                GET_MESSAGE_INFO_ENTRY(WM_QUERYUISTATE);
#  endif //_WIN32_WINNT >= 0x0500

#endif //WINVER >= 0x0500

                GET_MESSAGE_INFO_ENTRY(WM_CTLCOLORMSGBOX);    //��windows������Ϣ��ǰ���ʹ���Ϣ����Ϣ��������ߴ��ڣ�ͨ����Ӧ������Ϣ�������ߴ��ڿ���
                //  ͨ��ʹ�ø����������ʾ�豸�ľ����������Ϣ����ı��ͱ�����ɫ
                GET_MESSAGE_INFO_ENTRY(WM_CTLCOLOREDIT);      //��һ���༭�Ϳؼ���Ҫ������ʱ���ʹ���Ϣ�����ĸ����� -- �������ñ༭����ı��ͱ�����ɫ
                GET_MESSAGE_INFO_ENTRY(WM_CTLCOLORLISTBOX);   //��һ���б���ؼ���Ҫ������ǰ���ʹ���Ϣ�����ĸ����� -- ���������б�����ı��ͱ�����ɫ
                GET_MESSAGE_INFO_ENTRY(WM_CTLCOLORBTN);       //��һ����ť  �ؼ���Ҫ������ʱ���ʹ���Ϣ�����ĸ����� -- �������ð�Ŧ���ı��ͱ�����ɫ
                GET_MESSAGE_INFO_ENTRY(WM_CTLCOLORDLG);       //��һ���Ի���ؼ���Ҫ������ǰ���ʹ���Ϣ�����ĸ����� -- �������öԻ�����ı�������ɫ
                GET_MESSAGE_INFO_ENTRY(WM_CTLCOLORSCROLLBAR); //��һ���������ؼ���Ҫ������ʱ���ʹ���Ϣ�����ĸ����� -- �������ù������ı�����ɫ
                GET_MESSAGE_INFO_ENTRY(WM_CTLCOLORSTATIC);    //��һ����̬�ؼ���Ҫ������ʱ���ʹ���Ϣ�����ĸ����� -- �������þ�̬�ؼ����ı��ͱ�����ɫ
                GET_MESSAGE_INFO_ENTRY(MN_GETHMENU);


                //GET_MESSAGE_INFO_ENTRY(WM_MOUSEFIRST);
                GET_MESSAGE_INFO_ENTRY(WM_MOUSEMOVE);
                GET_MESSAGE_INFO_ENTRY(WM_LBUTTONDOWN);
                GET_MESSAGE_INFO_ENTRY(WM_LBUTTONUP);
                GET_MESSAGE_INFO_ENTRY(WM_LBUTTONDBLCLK);
                GET_MESSAGE_INFO_ENTRY(WM_RBUTTONDOWN);
                GET_MESSAGE_INFO_ENTRY(WM_RBUTTONUP);
                GET_MESSAGE_INFO_ENTRY(WM_RBUTTONDBLCLK);
                GET_MESSAGE_INFO_ENTRY(WM_MBUTTONDOWN);
                GET_MESSAGE_INFO_ENTRY(WM_MBUTTONUP);
                GET_MESSAGE_INFO_ENTRY(WM_MBUTTONDBLCLK);

#if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
                GET_MESSAGE_INFO_ENTRY(WM_MOUSEWHEEL);        //���������ת��ʱ���ʹ���Ϣ����ǰ�н���Ŀؼ�
#endif

#if (_WIN32_WINNT >= 0x0500)                
                GET_MESSAGE_INFO_ENTRY(WM_XBUTTONDOWN);
                GET_MESSAGE_INFO_ENTRY(WM_XBUTTONUP);
                GET_MESSAGE_INFO_ENTRY(WM_XBUTTONDBLCLK);
#endif

                //GET_MESSAGE_INFO_ENTRY(WM_MOUSELAST);

                GET_MESSAGE_INFO_ENTRY(WM_PARENTNOTIFY); //��MDI�Ӵ��ڱ����������٣����û�����һ��������������Ӵ�����ʱ���ʹ���Ϣ�����ĸ�����
                GET_MESSAGE_INFO_ENTRY(WM_ENTERMENULOOP); //���ʹ���Ϣ֪ͨӦ�ó���������� �Ѿ������˲˵�ѭ��ģʽ -- ?
                GET_MESSAGE_INFO_ENTRY(WM_EXITMENULOOP);  //���ʹ���Ϣ֪ͨӦ�ó���������� �Ѿ��˳��˲˵�ѭ��ģʽ -- ?

#if(WINVER >= 0x0400)
                GET_MESSAGE_INFO_ENTRY(WM_NEXTMENU);
                GET_MESSAGE_INFO_ENTRY(WM_SIZING);        //���û����ڵ������ڴ�Сʱ���ʹ���Ϣ�����ڣ�ͨ������ϢӦ�ó�����Լ��Ӻ��޸Ĵ��ڴ�С��λ��
                GET_MESSAGE_INFO_ENTRY(WM_CAPTURECHANGED);//����ʧȥ��������ʱ
                GET_MESSAGE_INFO_ENTRY(WM_MOVING);        //���û����ƶ�����ʱ���ʹ���Ϣ
#endif

#if(WINVER >= 0x0400)
                GET_MESSAGE_INFO_ENTRY(WM_POWERBROADCAST);//�͸�Ӧ�ó�����֪ͨ���йص�Դ�����¼�
                GET_MESSAGE_INFO_ENTRY(WM_DEVICECHANGE);  //���豸��Ӳ�����øı�ʱ���ʹ���Ϣ��Ӧ�ó�����豸��������
#endif

                GET_MESSAGE_INFO_ENTRY(WM_MDICREATE);     //Ҫ�󴴽�һ��MDI �Ӵ���
                GET_MESSAGE_INFO_ENTRY(WM_MDIDESTROY);
                GET_MESSAGE_INFO_ENTRY(WM_MDIACTIVATE);
                GET_MESSAGE_INFO_ENTRY(WM_MDIRESTORE);
                GET_MESSAGE_INFO_ENTRY(WM_MDINEXT);
                GET_MESSAGE_INFO_ENTRY(WM_MDIMAXIMIZE);
                GET_MESSAGE_INFO_ENTRY(WM_MDITILE);
                GET_MESSAGE_INFO_ENTRY(WM_MDICASCADE);
                GET_MESSAGE_INFO_ENTRY(WM_MDIICONARRANGE);
                GET_MESSAGE_INFO_ENTRY(WM_MDIGETACTIVE);


                GET_MESSAGE_INFO_ENTRY(WM_MDISETMENU);
                GET_MESSAGE_INFO_ENTRY(WM_ENTERSIZEMOVE);
                GET_MESSAGE_INFO_ENTRY(WM_EXITSIZEMOVE);
                GET_MESSAGE_INFO_ENTRY(WM_DROPFILES);
                GET_MESSAGE_INFO_ENTRY(WM_MDIREFRESHMENU);

#if(WINVER >= 0x0400)
                GET_MESSAGE_INFO_ENTRY(WM_IME_SETCONTEXT);
                GET_MESSAGE_INFO_ENTRY(WM_IME_NOTIFY);
                GET_MESSAGE_INFO_ENTRY(WM_IME_CONTROL);
                GET_MESSAGE_INFO_ENTRY(WM_IME_COMPOSITIONFULL);
                GET_MESSAGE_INFO_ENTRY(WM_IME_SELECT);
                GET_MESSAGE_INFO_ENTRY(WM_IME_CHAR);
#endif

#if(WINVER >= 0x0500)
                GET_MESSAGE_INFO_ENTRY(WM_IME_REQUEST);
#endif

#if(WINVER >= 0x0400)
                GET_MESSAGE_INFO_ENTRY(WM_IME_KEYDOWN);
                GET_MESSAGE_INFO_ENTRY(WM_IME_KEYUP);
#endif

#if((_WIN32_WINNT >= 0x0400) || (WINVER >= 0x0500))
                GET_MESSAGE_INFO_ENTRY(WM_MOUSEHOVER); //
                GET_MESSAGE_INFO_ENTRY(WM_MOUSELEAVE); //����ƿ�ʱ����Ҫ�� ON_MESSAGE ��Ӧ
#endif

#if(WINVER >= 0x0500)
                GET_MESSAGE_INFO_ENTRY(WM_NCMOUSEHOVER);
                GET_MESSAGE_INFO_ENTRY(WM_NCMOUSELEAVE);
#endif


#if(_WIN32_WINNT >= 0x0501)
                GET_MESSAGE_INFO_ENTRY(WM_WTSSESSION_CHANGE);
                GET_MESSAGE_INFO_ENTRY(WM_TABLET_FIRST);
                GET_MESSAGE_INFO_ENTRY(WM_TABLET_LAST);
#endif

                GET_MESSAGE_INFO_ENTRY(WM_CUT);
                GET_MESSAGE_INFO_ENTRY(WM_COPY);
                GET_MESSAGE_INFO_ENTRY(WM_PASTE);
                GET_MESSAGE_INFO_ENTRY(WM_CLEAR);
                GET_MESSAGE_INFO_ENTRY(WM_UNDO);
                GET_MESSAGE_INFO_ENTRY(WM_RENDERFORMAT);
                GET_MESSAGE_INFO_ENTRY(WM_RENDERALLFORMATS);
                GET_MESSAGE_INFO_ENTRY(WM_DESTROYCLIPBOARD);
                GET_MESSAGE_INFO_ENTRY(WM_DRAWCLIPBOARD); //������������ݱ仯ʱ���ʹ���Ϣ��������۲����ĵ�һ�����ڣ��������ü�����۲촰������ʾ�������������
                GET_MESSAGE_INFO_ENTRY(WM_PAINTCLIPBOARD);//�����������CF_OWNERDIPLAY��ʽ�����ݲ��Ҽ�����۲촰�ڵĿͻ�����Ҫ�ػ�
                GET_MESSAGE_INFO_ENTRY(WM_VSCROLLCLIPBOARD);
                GET_MESSAGE_INFO_ENTRY(WM_SIZECLIPBOARD);
                GET_MESSAGE_INFO_ENTRY(WM_ASKCBFORMATNAME);
                GET_MESSAGE_INFO_ENTRY(WM_CHANGECBCHAIN); //��һ�����ڴӼ�����۲�������ȥʱ���ʹ���Ϣ��������۲����ĵ�һ������
                GET_MESSAGE_INFO_ENTRY(WM_HSCROLLCLIPBOARD);
                GET_MESSAGE_INFO_ENTRY(WM_QUERYNEWPALETTE);   //����Ϣ��ʹ�������յ�����ʱͬʱ�л���ʵ�������߼���ɫ��
                GET_MESSAGE_INFO_ENTRY(WM_PALETTEISCHANGING);
                GET_MESSAGE_INFO_ENTRY(WM_PALETTECHANGED);
                GET_MESSAGE_INFO_ENTRY(WM_HOTKEY);        //���û�������REGISTERHOTKEY����ע����ȼ�ʱ�ύ����Ϣ

#if(WINVER >= 0x0400)
                GET_MESSAGE_INFO_ENTRY(WM_PRINT);
                GET_MESSAGE_INFO_ENTRY(WM_PRINTCLIENT);
#endif

#if(_WIN32_WINNT >= 0x0500)
                GET_MESSAGE_INFO_ENTRY(WM_APPCOMMAND);
#endif

#if(_WIN32_WINNT >= 0x0501)
                GET_MESSAGE_INFO_ENTRY(WM_THEMECHANGED);
                GET_MESSAGE_INFO_ENTRY(WM_CLIPBOARDUPDATE); // 0x031D          
#endif /* _WIN32_WINNT >= 0x0501 */


#if(_WIN32_WINNT >= 0x0600)
                GET_MESSAGE_INFO_ENTRY(WM_DWMCOMPOSITIONCHANGED);  //0x031E
                GET_MESSAGE_INFO_ENTRY(WM_DWMNCRENDERINGCHANGED);  //0x031F
                GET_MESSAGE_INFO_ENTRY(WM_DWMCOLORIZATIONCOLORCHANGED);//0x0320
                GET_MESSAGE_INFO_ENTRY(WM_DWMWINDOWMAXIMIZEDCHANGE);   //0x0321
#endif /* _WIN32_WINNT >= 0x0600 */ 

#if(WINVER >= 0x0400)
                GET_MESSAGE_INFO_ENTRY(WM_HANDHELDFIRST);
                GET_MESSAGE_INFO_ENTRY(WM_HANDHELDLAST);
#ifdef __AFXPRIV_H__
                //#  ifdef USING_MFC
                GET_MESSAGE_INFO_ENTRY(WM_QUERYAFXWNDPROC);
                GET_MESSAGE_INFO_ENTRY(WM_SIZEPARENT);
                GET_MESSAGE_INFO_ENTRY(WM_SETMESSAGESTRING);
                GET_MESSAGE_INFO_ENTRY(WM_IDLEUPDATECMDUI);
                GET_MESSAGE_INFO_ENTRY(WM_INITIALUPDATE);
                GET_MESSAGE_INFO_ENTRY(WM_COMMANDHELP);
                GET_MESSAGE_INFO_ENTRY(WM_HELPHITTEST);
                GET_MESSAGE_INFO_ENTRY(WM_EXITHELPMODE);
                GET_MESSAGE_INFO_ENTRY(WM_RECALCPARENT);
                GET_MESSAGE_INFO_ENTRY(WM_SIZECHILD);
                GET_MESSAGE_INFO_ENTRY(WM_KICKIDLE);
                GET_MESSAGE_INFO_ENTRY(WM_QUERYCENTERWND);
                GET_MESSAGE_INFO_ENTRY(WM_DISABLEMODAL);
                GET_MESSAGE_INFO_ENTRY(WM_FLOATSTATUS);
                GET_MESSAGE_INFO_ENTRY(WM_ACTIVATETOPLEVEL);
                GET_MESSAGE_INFO_ENTRY(WM_RESERVED_036F);
                GET_MESSAGE_INFO_ENTRY(WM_RESERVED_0370);
                GET_MESSAGE_INFO_ENTRY(WM_RESERVED_0371);
                GET_MESSAGE_INFO_ENTRY(WM_RESERVED_0372);
                GET_MESSAGE_INFO_ENTRY(WM_SOCKET_NOTIFY);
                GET_MESSAGE_INFO_ENTRY(WM_SOCKET_DEAD);
                GET_MESSAGE_INFO_ENTRY(WM_POPMESSAGESTRING);
                GET_MESSAGE_INFO_ENTRY(WM_HELPPROMPTADDR);
                //GET_MESSAGE_INFO_ENTRY(WM_OCC_LOADFROMSTREAM);
                GET_MESSAGE_INFO_ENTRY(WM_OCC_LOADFROMSTORAGE);
                GET_MESSAGE_INFO_ENTRY(WM_OCC_INITNEW);
                GET_MESSAGE_INFO_ENTRY(WM_OCC_LOADFROMSTREAM_EX);
                GET_MESSAGE_INFO_ENTRY(WM_OCC_LOADFROMSTORAGE_EX);
                GET_MESSAGE_INFO_ENTRY(WM_QUEUE_SENTINEL);
                GET_MESSAGE_INFO_ENTRY(WM_RESERVED_037C);
                GET_MESSAGE_INFO_ENTRY(WM_RESERVED_037D);
                GET_MESSAGE_INFO_ENTRY(WM_RESERVED_037E);
                GET_MESSAGE_INFO_ENTRY(WM_FORWARDMSG);
#  else
                GET_MESSAGE_INFO_ENTRY(WM_AFXFIRST);
                GET_MESSAGE_INFO_ENTRY(WM_AFXLAST);

#  endif //end __AFXPRIV_H__

#endif

                GET_MESSAGE_INFO_ENTRY(WM_PENWINFIRST);
                GET_MESSAGE_INFO_ENTRY(WM_PENWINLAST);
#  ifdef _DDEHEADER_INCLUDED_
                GET_MESSAGE_INFO_ENTRY(WM_DDE_INITIATE);  //һ��DDE�ͻ������ύ����Ϣ��ʼһ�������������ĻỰ����Ӧ�Ǹ�ָ���ĳ����������
                GET_MESSAGE_INFO_ENTRY(WM_DDE_TERMINATE);
                GET_MESSAGE_INFO_ENTRY(WM_DDE_ADVISE);
                GET_MESSAGE_INFO_ENTRY(WM_DDE_UNADVISE);
                GET_MESSAGE_INFO_ENTRY(WM_DDE_ACK);
                GET_MESSAGE_INFO_ENTRY(WM_DDE_DATA);
                GET_MESSAGE_INFO_ENTRY(WM_DDE_REQUEST);
                GET_MESSAGE_INFO_ENTRY(WM_DDE_POKE);
                GET_MESSAGE_INFO_ENTRY(WM_DDE_EXECUTE);
                //GET_MESSAGE_INFO_ENTRY(WM_DDE_LAST);
#  endif
#if(WINVER >= 0x0400)
                GET_MESSAGE_INFO_ENTRY(WM_APP);
#endif
                GET_MESSAGE_INFO_ENTRY(DM_GETDEFID);
                GET_MESSAGE_INFO_ENTRY(DM_SETDEFID);
#if(WINVER >= 0x0400)
                GET_MESSAGE_INFO_ENTRY(DM_REPOSITION);
#endif

				//Edit Control Messages
				GET_MESSAGE_INFO_ENTRY(EM_GETSEL);
				GET_MESSAGE_INFO_ENTRY(EM_SETSEL);
				GET_MESSAGE_INFO_ENTRY(EM_GETRECT);
				GET_MESSAGE_INFO_ENTRY(EM_SETRECT);
				GET_MESSAGE_INFO_ENTRY(EM_SETRECTNP);
				GET_MESSAGE_INFO_ENTRY(EM_SCROLL);
				GET_MESSAGE_INFO_ENTRY(EM_LINESCROLL);
				GET_MESSAGE_INFO_ENTRY(EM_SCROLLCARET);
				GET_MESSAGE_INFO_ENTRY(EM_GETMODIFY);
				GET_MESSAGE_INFO_ENTRY(EM_SETMODIFY);
				GET_MESSAGE_INFO_ENTRY(EM_GETLINECOUNT);
				GET_MESSAGE_INFO_ENTRY(EM_LINEINDEX);
				GET_MESSAGE_INFO_ENTRY(EM_SETHANDLE);
				GET_MESSAGE_INFO_ENTRY(EM_GETHANDLE);
				GET_MESSAGE_INFO_ENTRY(EM_GETTHUMB);
				GET_MESSAGE_INFO_ENTRY(EM_LINELENGTH);
				GET_MESSAGE_INFO_ENTRY(EM_REPLACESEL);
				GET_MESSAGE_INFO_ENTRY(EM_GETLINE);
				GET_MESSAGE_INFO_ENTRY(EM_LIMITTEXT); //EM_SETLIMITTEXT
				GET_MESSAGE_INFO_ENTRY(EM_CANUNDO);
				GET_MESSAGE_INFO_ENTRY(EM_UNDO);
				GET_MESSAGE_INFO_ENTRY(EM_FMTLINES);
				GET_MESSAGE_INFO_ENTRY(EM_LINEFROMCHAR);
				GET_MESSAGE_INFO_ENTRY(EM_SETTABSTOPS);
				GET_MESSAGE_INFO_ENTRY(EM_SETPASSWORDCHAR);
				GET_MESSAGE_INFO_ENTRY(EM_EMPTYUNDOBUFFER);
				GET_MESSAGE_INFO_ENTRY(EM_GETFIRSTVISIBLELINE);
				GET_MESSAGE_INFO_ENTRY(EM_SETREADONLY);
				GET_MESSAGE_INFO_ENTRY(EM_SETWORDBREAKPROC);
				GET_MESSAGE_INFO_ENTRY(EM_GETWORDBREAKPROC);
				GET_MESSAGE_INFO_ENTRY(EM_GETPASSWORDCHAR);
				GET_MESSAGE_INFO_ENTRY(EM_SETMARGINS);
				GET_MESSAGE_INFO_ENTRY(EM_GETMARGINS);
				GET_MESSAGE_INFO_ENTRY(EM_GETLIMITTEXT);
				GET_MESSAGE_INFO_ENTRY(EM_POSFROMCHAR);
				GET_MESSAGE_INFO_ENTRY(EM_CHARFROMPOS);
#if(WINVER >= 0x0500)
				GET_MESSAGE_INFO_ENTRY(EM_SETIMESTATUS);
				GET_MESSAGE_INFO_ENTRY(EM_GETIMESTATUS);
#endif /* WINVER >= 0x0500 */

				//Button Control Messages
				GET_MESSAGE_INFO_ENTRY(BM_GETCHECK);
				GET_MESSAGE_INFO_ENTRY(BM_SETCHECK);
				GET_MESSAGE_INFO_ENTRY(BM_GETSTATE);
				GET_MESSAGE_INFO_ENTRY(BM_SETSTATE);
				GET_MESSAGE_INFO_ENTRY(BM_SETSTYLE);
#if(WINVER >= 0x0400)
				GET_MESSAGE_INFO_ENTRY(BM_CLICK);
				GET_MESSAGE_INFO_ENTRY(BM_GETIMAGE);
				GET_MESSAGE_INFO_ENTRY(BM_SETIMAGE);
#endif /* WINVER >= 0x0400 */

#if(WINVER >= 0x0600)
				GET_MESSAGE_INFO_ENTRY(BM_SETDONTCLICK);
#endif /* WINVER >= 0x0600 */

				//Listbox messages
				GET_MESSAGE_INFO_ENTRY(LB_ADDSTRING);
				GET_MESSAGE_INFO_ENTRY(LB_INSERTSTRING);
				GET_MESSAGE_INFO_ENTRY(LB_DELETESTRING);
				GET_MESSAGE_INFO_ENTRY(LB_SELITEMRANGEEX);
				GET_MESSAGE_INFO_ENTRY(LB_RESETCONTENT);
				GET_MESSAGE_INFO_ENTRY(LB_SETSEL);
				GET_MESSAGE_INFO_ENTRY(LB_SETCURSEL);
				GET_MESSAGE_INFO_ENTRY(LB_GETSEL);
				GET_MESSAGE_INFO_ENTRY(LB_GETCURSEL);
				GET_MESSAGE_INFO_ENTRY(LB_GETTEXT);
				GET_MESSAGE_INFO_ENTRY(LB_GETTEXTLEN);
				GET_MESSAGE_INFO_ENTRY(LB_GETCOUNT);
				GET_MESSAGE_INFO_ENTRY(LB_SELECTSTRING);
				GET_MESSAGE_INFO_ENTRY(LB_DIR);
				GET_MESSAGE_INFO_ENTRY(LB_GETTOPINDEX);
				GET_MESSAGE_INFO_ENTRY(LB_FINDSTRING);
				GET_MESSAGE_INFO_ENTRY(LB_GETSELCOUNT);
				GET_MESSAGE_INFO_ENTRY(LB_GETSELITEMS);
				GET_MESSAGE_INFO_ENTRY(LB_SETTABSTOPS);
				GET_MESSAGE_INFO_ENTRY(LB_GETHORIZONTALEXTENT);
				GET_MESSAGE_INFO_ENTRY(LB_SETHORIZONTALEXTENT);
				GET_MESSAGE_INFO_ENTRY(LB_SETCOLUMNWIDTH);
				GET_MESSAGE_INFO_ENTRY(LB_ADDFILE);
				GET_MESSAGE_INFO_ENTRY(LB_SETTOPINDEX);
				GET_MESSAGE_INFO_ENTRY(LB_GETITEMRECT);
				GET_MESSAGE_INFO_ENTRY(LB_GETITEMDATA);
				GET_MESSAGE_INFO_ENTRY(LB_SETITEMDATA);
				GET_MESSAGE_INFO_ENTRY(LB_SELITEMRANGE);
				GET_MESSAGE_INFO_ENTRY(LB_SETANCHORINDEX);
				GET_MESSAGE_INFO_ENTRY(LB_GETANCHORINDEX);
				GET_MESSAGE_INFO_ENTRY(LB_SETCARETINDEX);
				GET_MESSAGE_INFO_ENTRY(LB_GETCARETINDEX);
				GET_MESSAGE_INFO_ENTRY(LB_SETITEMHEIGHT);
				GET_MESSAGE_INFO_ENTRY(LB_GETITEMHEIGHT);
				GET_MESSAGE_INFO_ENTRY(LB_FINDSTRINGEXACT);
				GET_MESSAGE_INFO_ENTRY(LB_SETLOCALE);
				GET_MESSAGE_INFO_ENTRY(LB_GETLOCALE);
				GET_MESSAGE_INFO_ENTRY(LB_SETCOUNT);
#if(WINVER >= 0x0400)
				GET_MESSAGE_INFO_ENTRY(LB_INITSTORAGE);
				GET_MESSAGE_INFO_ENTRY(LB_ITEMFROMPOINT);
#endif /* WINVER >= 0x0400 */

#if(_WIN32_WCE >= 0x0400)
				GET_MESSAGE_INFO_ENTRY(LB_MULTIPLEADDSTRING);
#endif //_WIN32_WCE >= 0x0400

#if(_WIN32_WINNT >= 0x0501)
				GET_MESSAGE_INFO_ENTRY(LB_GETLISTBOXINFO);
#endif /* _WIN32_WINNT >= 0x0501 */

//#if(_WIN32_WINNT >= 0x0501)
				GET_MESSAGE_INFO_ENTRY(LB_MSGMAX);
//#endif //_WIN32_WINNT

				//Combo Box messages
				GET_MESSAGE_INFO_ENTRY(CB_GETEDITSEL);
				GET_MESSAGE_INFO_ENTRY(CB_LIMITTEXT);
				GET_MESSAGE_INFO_ENTRY(CB_SETEDITSEL);
				GET_MESSAGE_INFO_ENTRY(CB_ADDSTRING);
				GET_MESSAGE_INFO_ENTRY(CB_DELETESTRING);
				GET_MESSAGE_INFO_ENTRY(CB_DIR);
				GET_MESSAGE_INFO_ENTRY(CB_GETCOUNT);
				GET_MESSAGE_INFO_ENTRY(CB_GETCURSEL);
				GET_MESSAGE_INFO_ENTRY(CB_GETLBTEXT);
				GET_MESSAGE_INFO_ENTRY(CB_GETLBTEXTLEN);
				GET_MESSAGE_INFO_ENTRY(CB_INSERTSTRING);
				GET_MESSAGE_INFO_ENTRY(CB_RESETCONTENT);
				GET_MESSAGE_INFO_ENTRY(CB_FINDSTRING);
				GET_MESSAGE_INFO_ENTRY(CB_SELECTSTRING);
				GET_MESSAGE_INFO_ENTRY(CB_SETCURSEL);
				GET_MESSAGE_INFO_ENTRY(CB_SHOWDROPDOWN);
				GET_MESSAGE_INFO_ENTRY(CB_GETITEMDATA);
				GET_MESSAGE_INFO_ENTRY(CB_SETITEMDATA);
				GET_MESSAGE_INFO_ENTRY(CB_GETDROPPEDCONTROLRECT);
				GET_MESSAGE_INFO_ENTRY(CB_SETITEMHEIGHT);
				GET_MESSAGE_INFO_ENTRY(CB_GETITEMHEIGHT);
				GET_MESSAGE_INFO_ENTRY(CB_SETEXTENDEDUI);
				GET_MESSAGE_INFO_ENTRY(CB_GETEXTENDEDUI);
				GET_MESSAGE_INFO_ENTRY(CB_GETDROPPEDSTATE);
				GET_MESSAGE_INFO_ENTRY(CB_FINDSTRINGEXACT);
				GET_MESSAGE_INFO_ENTRY(CB_SETLOCALE);
				GET_MESSAGE_INFO_ENTRY(CB_GETLOCALE);
				GET_MESSAGE_INFO_ENTRY(CB_GETTOPINDEX);
				GET_MESSAGE_INFO_ENTRY(CB_SETTOPINDEX);
				GET_MESSAGE_INFO_ENTRY(CB_GETHORIZONTALEXTENT);
				GET_MESSAGE_INFO_ENTRY(CB_SETHORIZONTALEXTENT);
				GET_MESSAGE_INFO_ENTRY(CB_GETDROPPEDWIDTH);
				GET_MESSAGE_INFO_ENTRY(CB_SETDROPPEDWIDTH);
				GET_MESSAGE_INFO_ENTRY(CB_INITSTORAGE);
#if(_WIN32_WCE >= 0x0400)
				GET_MESSAGE_INFO_ENTRY(CB_MULTIPLEADDSTRING);
#endif //_WIN32_WCE >= 0x0400
				GET_MESSAGE_INFO_ENTRY(CB_GETCOMBOBOXINFO);
				GET_MESSAGE_INFO_ENTRY(CB_MSGMAX);

				//Scroll bar messages
				GET_MESSAGE_INFO_ENTRY(SBM_SETPOS);
				GET_MESSAGE_INFO_ENTRY(SBM_GETPOS);
				GET_MESSAGE_INFO_ENTRY(SBM_SETRANGE);
				GET_MESSAGE_INFO_ENTRY(SBM_SETRANGEREDRAW);
				GET_MESSAGE_INFO_ENTRY(SBM_GETRANGE);
				GET_MESSAGE_INFO_ENTRY(SBM_ENABLE_ARROWS);
				GET_MESSAGE_INFO_ENTRY(SBM_SETSCROLLINFO);
				GET_MESSAGE_INFO_ENTRY(SBM_GETSCROLLINFO);

#if(_WIN32_WINNT >= 0x0501)
				GET_MESSAGE_INFO_ENTRY(SBM_GETSCROLLBARINFO);
#endif /* _WIN32_WINNT >= 0x0501 */

                //Reflected Window Message IDs
                GET_MESSAGE_INFO_ENTRY(OCM_COMMAND);

#ifdef _WIN32
                GET_MESSAGE_INFO_ENTRY(OCM_CTLCOLORBTN);
                GET_MESSAGE_INFO_ENTRY(OCM_CTLCOLOREDIT);
                GET_MESSAGE_INFO_ENTRY(OCM_CTLCOLORDLG);
                GET_MESSAGE_INFO_ENTRY(OCM_CTLCOLORLISTBOX);
                GET_MESSAGE_INFO_ENTRY(OCM_CTLCOLORMSGBOX);
                GET_MESSAGE_INFO_ENTRY(OCM_CTLCOLORSCROLLBAR);
                GET_MESSAGE_INFO_ENTRY(OCM_CTLCOLORSTATIC);
#else 
                GET_MESSAGE_INFO_ENTRY(OCM_CTLCOLOR);
#endif //ifndef _WIN32

                GET_MESSAGE_INFO_ENTRY(OCM_DRAWITEM);
                GET_MESSAGE_INFO_ENTRY(OCM_MEASUREITEM);
                GET_MESSAGE_INFO_ENTRY(OCM_DELETEITEM);
                GET_MESSAGE_INFO_ENTRY(OCM_VKEYTOITEM);
                GET_MESSAGE_INFO_ENTRY(OCM_CHARTOITEM);
                GET_MESSAGE_INFO_ENTRY(OCM_COMPAREITEM);
                GET_MESSAGE_INFO_ENTRY(OCM_HSCROLL);
                GET_MESSAGE_INFO_ENTRY(OCM_VSCROLL);
                GET_MESSAGE_INFO_ENTRY(OCM_PARENTNOTIFY);
                GET_MESSAGE_INFO_ENTRY(OCM_NOTIFY);
				//GET_MESSAGE_INFO_ENTRY(XXXXXXXXXXXXXXXXX);
            default:
				if (m_Info > WM_USER)
				{
					UINT userMsg = m_Info - WM_USER;
					StringCchPrintf(m_bufInfo,_countof(m_bufInfo),
						TEXT("0x%08x = (WM_USER+%d[0x%x])"),m_Info, userMsg, userMsg );
				}
				else
				{
					StringCchPrintf(m_bufInfo,_countof(m_bufInfo),
						TEXT("Unknown Message %d(0x%08x)"),m_Info,m_Info);
				}
            }
        }
        return m_bufInfo;
    }//CFMessageInfo


    ///////////////////////////////////////////////////////////////////////////////////////////////////

    template <typename T, typename TWindowAutoSizeTraits >
    CFWindowAutoSize<T,TWindowAutoSizeTraits>::CFWindowAutoSize()
    {
        m_sizeWindow.cx = 0;
        m_sizeWindow.cy = 0; 
        m_ptMinTrackSize.x = -1;
        m_ptMinTrackSize.y = -1;
        m_bGripper = FALSE;
    }

    template <typename T, typename TWindowAutoSizeTraits >
    BOOL CFWindowAutoSize<T,TWindowAutoSizeTraits>::InitAutoSizeInfo(BOOL bAddGripper /* = TRUE */, BOOL bUseMinTrackSize /* = TRUE */)
    {
        BOOL bRet = FALSE;
        T* pT = static_cast<T*>(this);
        HWND hWnd = TWindowAutoSizeTraits::GetWinHwndProxy(pT);
        FTLASSERT(::IsWindow(hWnd));
        DWORD dwStyle = (DWORD)::GetWindowLong(hWnd, GWL_STYLE);
#ifdef FTL_DEBUG
        // Debug only: Check if top level dialogs have a resizeable border.
        if(((dwStyle & WS_CHILD) == 0) && ((dwStyle & WS_THICKFRAME) == 0))
        {
            FTLTRACEEX(tlWarning,TEXT("top level dialog without the WS_THICKFRAME style - user cannot resize it\n"));
        }
#endif // _DEBUG

        {
            // Cleanup in case of multiple initialization
            // block: first check for the gripper control, destroy it if needed
            HWND HwndGripper = ::GetDlgItem(hWnd, TWindowAutoSizeTraits::GetStatusBarCtrlID());
            if( ::IsWindow(HwndGripper) && m_allResizeData.size() > 0 && (m_allResizeData[0].m_dwResizeFlags & _WINSZ_GRIPPER) != 0)
            {
                API_VERIFY(::DestroyWindow(HwndGripper));
            }
        }
        // clear out everything else
        m_allResizeData.clear();
        m_sizeWindow.cx = 0;
        m_sizeWindow.cy = 0;
        m_ptMinTrackSize.x = -1;
        m_ptMinTrackSize.y = -1;

        // Get initial dialog client size
        RECT rectDlg = { 0 };
        API_VERIFY(::GetClientRect(hWnd,&rectDlg));
        m_sizeWindow.cx = rectDlg.right;
        m_sizeWindow.cy = rectDlg.bottom;

       // Create gripper if requested
        m_bGripper = FALSE;
        if(bAddGripper)
        {
            // shouldn't exist already
            FTLASSERT(!::IsWindow(::GetDlgItem(hWnd, TWindowAutoSizeTraits::GetStatusBarCtrlID())));
            if(!::IsWindow(::GetDlgItem(hWnd, TWindowAutoSizeTraits::GetStatusBarCtrlID())))
            {
                HWND hWndGripper = ::CreateWindowEx(0,_T("SCROLLBAR"),NULL, 
                    WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | SBS_SIZEBOX | SBS_SIZEGRIP | SBS_SIZEBOXBOTTOMRIGHTALIGN,
                    rectDlg.left,
                    rectDlg.top,
                    rectDlg.right - rectDlg.left,
                    rectDlg.bottom - rectDlg.top,
                    hWnd,
                    (HMENU)(TWindowAutoSizeTraits::GetStatusBarCtrlID()), 
                    NULL,
                    NULL);
                FTLASSERT(::IsWindow(hWndGripper));
                if(::IsWindow(hWndGripper))
                {
                    m_bGripper = TRUE;
                    RECT rectCtl = { 0 };
                    API_VERIFY(::GetWindowRect(hWndGripper,&rectCtl));
                    API_VERIFY(::MapWindowPoints(NULL, hWnd, (LPPOINT)&rectCtl, 2) != 0);
                    _WindowResizeData data = 
                    {
                        TWindowAutoSizeTraits::GetStatusBarCtrlID(), 
                        WINSZ_MOVE_X | WINSZ_MOVE_Y | WINSZ_REPAINT | _WINSZ_GRIPPER, 
                        { 
                            rectCtl.left, 
                            rectCtl.top, 
                            rectCtl.right, 
                            rectCtl.bottom 
                        }
                    };
                    m_allResizeData.push_back(data);
                }
            }
        }

        // Get min track position if requested
        if(bUseMinTrackSize)
        {
            if((dwStyle & WS_CHILD) != 0)
            {
                RECT rect = { 0 };
                API_VERIFY(::GetClientRect(hWnd,&rect));
                m_ptMinTrackSize.x = rect.right - rect.left;
                m_ptMinTrackSize.y = rect.bottom - rect.top;
            }
            else
            {
                RECT rect = { 0 };
                API_VERIFY(::GetWindowRect(hWnd, &rect));
                m_ptMinTrackSize.x = rect.right - rect.left;
                m_ptMinTrackSize.y = rect.bottom - rect.top;
            }
        }

        // Walk the map and initialize data
        const _WindowResizeMap* pMap = pT->GetWindowResizeMap();
        FTLASSERT(pMap != NULL);
        int nGroupStart = -1;
        for(int nCount = 1; !(pMap->m_nCtlID == -1 && pMap->m_dwResizeFlags == 0); nCount++, pMap++)
        {
            if(pMap->m_nCtlID == -1)    //��ʼ�����һ����
            {
                switch(pMap->m_dwResizeFlags)
                {
                case _WINSZ_BEGIN_GROUP:
                    FTLASSERT(nGroupStart == -1);
                    nGroupStart = static_cast<int>(m_allResizeData.size());
                    break;
                case _WINSZ_END_GROUP:
                    {
                        FTLASSERT(nGroupStart != -1);
                        int nGroupCount = static_cast<int>(m_allResizeData.size()) - nGroupStart;
                        m_allResizeData[nGroupStart].SetGroupCount(nGroupCount);
                        nGroupStart = -1;
                    }
                    break;
                default:
                    FTLASSERT(FALSE && _T("Invalid WINDOWRESIZE Map Entry"));
                    break;
                }
            }
            else
            {
                // this ID conflicts with the default gripper one
                FTLASSERT(m_bGripper ? (pMap->m_nCtlID != TWindowAutoSizeTraits::GetStatusBarCtrlID()) : TRUE);
                HWND hWndCtrl = ::GetDlgItem(hWnd,pMap->m_nCtlID);
                FTLASSERT(::IsWindow(hWndCtrl));
                RECT rectCtl = { 0 };
                API_VERIFY(::GetWindowRect(hWndCtrl,&rectCtl));
                API_VERIFY(::MapWindowPoints(NULL, hWnd, (LPPOINT)&rectCtl, 2)!= 0);

                DWORD dwGroupFlag = (nGroupStart != -1 && static_cast<int>(m_allResizeData.size()) == nGroupStart) ? _WINSZ_BEGIN_GROUP : 0;
                _WindowResizeData data = 
                {
                    pMap->m_nCtlID, 
                    pMap->m_dwResizeFlags | dwGroupFlag, 
                    { 
                        rectCtl.left, 
                        rectCtl.top, 
                        rectCtl.right, 
                        rectCtl.bottom 
                    } 
                };
                m_allResizeData.push_back(data);
            }
        }
        FTLASSERT((nGroupStart == -1) && _T("No End Group Entry in the WINDOWRESIZE Map"));
        return bRet;
    }

    template <typename T, typename TWindowAutoSizeTraits >
    BOOL CFWindowAutoSize<T,TWindowAutoSizeTraits>::AutoResizeUpdateLayout(int cxWidth, int cyHeight)
    {
        BOOL bRet = FALSE;
        T* pT = static_cast<T*>(this);
        HWND hWnd = TWindowAutoSizeTraits::GetWinHwndProxy(pT);

        FTLASSERT(::IsWindow(hWnd));

        // Restrict minimum size if requested
        if((((DWORD)::GetWindowLong(hWnd, GWL_STYLE) & WS_CHILD) != 0) && m_ptMinTrackSize.x != -1 && m_ptMinTrackSize.y != -1)
        {
            if(cxWidth < m_ptMinTrackSize.x)
            {
                cxWidth = m_ptMinTrackSize.x;
            }
            if(cyHeight < m_ptMinTrackSize.y)
            {
                cyHeight = m_ptMinTrackSize.y;
            }
        }

        BOOL bVisible = ::IsWindowVisible(hWnd);
        if(bVisible)
        {
            ::SendMessage(hWnd, WM_SETREDRAW, (WPARAM)FALSE, 0);
            //pT->SetRedraw(FALSE);
        }

        for(size_t i = 0; i < m_allResizeData.size(); i++)
        {
            if((m_allResizeData[i].m_dwResizeFlags & _WINSZ_BEGIN_GROUP) != 0)   // start of a group
            {
                int nGroupCount = m_allResizeData[i].GetGroupCount();
                FTLASSERT(nGroupCount > 0 && i + nGroupCount - 1 < m_allResizeData.size());
                RECT rectGroup = m_allResizeData[i].m_rect;

                int j = 1;
                for(j = 1; j < nGroupCount; j++)
                {
                    rectGroup.left = min(rectGroup.left, m_allResizeData[i + j].m_rect.left);
                    rectGroup.top = min(rectGroup.top, m_allResizeData[i + j].m_rect.top);
                    rectGroup.right = max(rectGroup.right, m_allResizeData[i + j].m_rect.right);
                    rectGroup.bottom = max(rectGroup.bottom, m_allResizeData[i + j].m_rect.bottom);
                }

                for(j = 0; j < nGroupCount; j++)
                {
                    _WindowResizeData* pDataPrev = NULL;
                    if(j > 0)
                        pDataPrev = &(m_allResizeData[i + j - 1]);
                    pT->AutoPositionControl(cxWidth, cyHeight, rectGroup, m_allResizeData[i + j], true, pDataPrev);
                }

                i += nGroupCount - 1;   // increment to skip all group controls
            }
            else // one control entry
            {
                RECT rectGroup = { 0, 0, 0, 0 };
                pT->AutoPositionControl(cxWidth, cyHeight, rectGroup, m_allResizeData[i], false);
            }
        }

        if(bVisible)
        {
            ::SendMessage(hWnd, WM_SETREDRAW, (WPARAM)TRUE, 0);
            //pT->SetRedraw(TRUE);
        }
        ::RedrawWindow(hWnd,NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_UPDATENOW | RDW_ALLCHILDREN);
        return bRet;
    }

    template <typename T, typename TWindowAutoSizeTraits >
    BOOL CFWindowAutoSize<T,TWindowAutoSizeTraits>::AutoPositionControl(int cxWidth, int cyHeight, 
        RECT& rectGroup, _WindowResizeData& data, 
        bool bGroup, _WindowResizeData* pDataPrev /* = NULL */)
    {
        //BOOL bRet = FALSE;
        T* pT = static_cast<T*>(this);
        HWND hWnd = TWindowAutoSizeTraits::GetWinHwndProxy(pT);
        FTLASSERT(::IsWindow(hWnd));

        HWND hWndCtrl = NULL;
        RECT rectCtl = { 0 };

        hWndCtrl = ::GetDlgItem(hWnd, data.m_nCtlID);
        FTLASSERT(::IsWindow(hWndCtrl));
        ::GetWindowRect(hWndCtrl, &rectCtl);
        ::MapWindowPoints(NULL, hWnd, (LPPOINT)&rectCtl, 2);

        if(bGroup)
        {
            if((data.m_dwResizeFlags & WINSZ_CENTER_X) != 0)
            {
                int cxRight = rectGroup.right + cxWidth - m_sizeWindow.cx;
                int cxCtl = data.m_rect.right - data.m_rect.left;
                rectCtl.left = rectGroup.left + (cxRight - rectGroup.left - cxCtl) / 2;
                rectCtl.right = rectCtl.left + cxCtl;
            }
            else if((data.m_dwResizeFlags & (WINSZ_SIZE_X | WINSZ_MOVE_X)) != 0)
            {
                rectCtl.left = rectGroup.left + ::MulDiv(data.m_rect.left - rectGroup.left, rectGroup.right - rectGroup.left + (cxWidth - m_sizeWindow.cx), rectGroup.right - rectGroup.left);

                if((data.m_dwResizeFlags & WINSZ_SIZE_X) != 0)
                {
                    rectCtl.right = rectGroup.left + ::MulDiv(data.m_rect.right - rectGroup.left, rectGroup.right - rectGroup.left + (cxWidth - m_sizeWindow.cx), rectGroup.right - rectGroup.left);

                    if(pDataPrev != NULL)
                    {
                        HWND hWndCtlPrev = ::GetDlgItem(hWnd,pDataPrev->m_nCtlID);
                        FTLASSERT(::IsWindow(hWndCtlPrev));
                        RECT rcPrev = { 0 };
                        ::GetWindowRect(hWndCtlPrev, &rcPrev);
                        ::MapWindowPoints(NULL, hWnd, (LPPOINT)&rcPrev, 2);
                        int dxAdjust = (rectCtl.left - rcPrev.right) - (data.m_rect.left - pDataPrev->m_rect.right);
                        rcPrev.right += dxAdjust;
                        ::SetWindowPos(hWndCtlPrev, NULL, rcPrev.left,rcPrev.top,rcPrev.right - rcPrev.left,
                            rcPrev.bottom-rcPrev.top,SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOMOVE);
                    }
                }
                else
                {
                    rectCtl.right = rectCtl.left + (data.m_rect.right - data.m_rect.left);
                }
            }

            if((data.m_dwResizeFlags & WINSZ_CENTER_Y) != 0)
            {
                int cyBottom = rectGroup.bottom + cyHeight - m_sizeWindow.cy;
                int cyCtl = data.m_rect.bottom - data.m_rect.top;
                rectCtl.top = rectGroup.top + (cyBottom - rectGroup.top - cyCtl) / 2;
                rectCtl.bottom = rectCtl.top + cyCtl;
            }
            else if((data.m_dwResizeFlags & (WINSZ_SIZE_Y | WINSZ_MOVE_Y)) != 0)
            {
                rectCtl.top = rectGroup.top + ::MulDiv(data.m_rect.top - rectGroup.top, rectGroup.bottom - rectGroup.top + (cyHeight - m_sizeWindow.cy), rectGroup.bottom - rectGroup.top);

                if((data.m_dwResizeFlags & WINSZ_SIZE_Y) != 0)
                {
                    rectCtl.bottom = rectGroup.top + ::MulDiv(data.m_rect.bottom - rectGroup.top, rectGroup.bottom - rectGroup.top + (cyHeight - m_sizeWindow.cy), rectGroup.bottom - rectGroup.top);

                    if(pDataPrev != NULL)
                    {
                        HWND hWndCtlPrev = ::GetDlgItem(hWnd, pDataPrev->m_nCtlID);
                        FTLASSERT(::IsWindow(hWndCtlPrev));
                        RECT rcPrev = { 0 };
                        ::GetWindowRect(hWndCtlPrev, &rcPrev);
                        ::MapWindowPoints(NULL, hWnd, (LPPOINT)&rcPrev, 2);
                        int dxAdjust = (rectCtl.top - rcPrev.bottom) - (data.m_rect.top - pDataPrev->m_rect.bottom);
                        rcPrev.bottom += dxAdjust;
                        ::SetWindowPos(hWndCtlPrev, NULL, rcPrev.left,rcPrev.top,rcPrev.right - rcPrev.left,
                            rcPrev.bottom-rcPrev.top,SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOMOVE);
                    }
                }
                else
                {
                    rectCtl.bottom = rectCtl.top + (data.m_rect.bottom - data.m_rect.top);
                }
            }
        }
        else // no group
        {
            if((data.m_dwResizeFlags & WINSZ_CENTER_X) != 0)
            {
                int cxCtl = data.m_rect.right - data.m_rect.left;
                rectCtl.left = (cxWidth - cxCtl) / 2;
                rectCtl.right = rectCtl.left + cxCtl;
            }
            else if((data.m_dwResizeFlags & (WINSZ_SIZE_X | WINSZ_MOVE_X)) != 0)
            {
                rectCtl.right = data.m_rect.right + (cxWidth - m_sizeWindow.cx);

                if((data.m_dwResizeFlags & WINSZ_MOVE_X) != 0)
                    rectCtl.left = rectCtl.right - (data.m_rect.right - data.m_rect.left);
            }

            if((data.m_dwResizeFlags & WINSZ_CENTER_Y) != 0)
            {
                int cyCtl = data.m_rect.bottom - data.m_rect.top;
                rectCtl.top = (cyHeight - cyCtl) / 2;
                rectCtl.bottom = rectCtl.top + cyCtl;
            }
            else if((data.m_dwResizeFlags & (WINSZ_SIZE_Y | WINSZ_MOVE_Y)) != 0)
            {
                rectCtl.bottom = data.m_rect.bottom + (cyHeight - m_sizeWindow.cy);

                if((data.m_dwResizeFlags & WINSZ_MOVE_Y) != 0)
                    rectCtl.top = rectCtl.bottom - (data.m_rect.bottom - data.m_rect.top);
            }
        }

        if((data.m_dwResizeFlags & WINSZ_REPAINT) != 0)
        {
            ::InvalidateRect(hWndCtrl, NULL, TRUE);
        }
        if((data.m_dwResizeFlags & (WINSZ_SIZE_X | WINSZ_SIZE_Y | WINSZ_MOVE_X | WINSZ_MOVE_Y | WINSZ_REPAINT | WINSZ_CENTER_X | WINSZ_CENTER_Y)) != 0)
        {
            ::SetWindowPos(hWndCtrl, NULL, rectCtl.left,rectCtl.top,rectCtl.right - rectCtl.left,
                rectCtl.bottom-rectCtl.top,SWP_NOZORDER | SWP_NOACTIVATE);

        }
        return TRUE;
    }

    BOOL CFWinUtil::SetWindowFullScreen(HWND hWnd,BOOL isFullScreen, BOOL &oldZoomedState)
    {
        BOOL bRet = FALSE;
        //��ȡ������ SM_CXFRAME, SM_CYFRAME, SM_CXScreen �Ĵ�С
        int cyCaption = ::GetSystemMetrics(SM_CYCAPTION);
        int cxFrame = ::GetSystemMetrics(SM_CXFRAME);
        int cyFrame = ::GetSystemMetrics(SM_CYFRAME);
        int cyMenu = ::GetSystemMetrics(SM_CYMENU);
        int cxScreen = ::GetSystemMetrics(SM_CXSCREEN);
        int cyScreen = ::GetSystemMetrics(SM_CYSCREEN);
        //int cxBorder = ::GetSystemMetrics(SM_CXBORDER);
        //int cyBorder = ::GetSystemMetrics(SM_CYBORDER);

        if (isFullScreen)
        {
            //oldZoomedState = ::IsZoomed(hWnd); //���浱ǰ�Ƿ������״̬
            //if(oldZoomedState) //��ǰ�����
            {
                BringWindowToTop(hWnd);
                bRet = ::SetWindowPos(hWnd,HWND_TOPMOST,-cxFrame,-(cyFrame + cyCaption + cyMenu),
                    cxScreen + 2 * cxFrame, cyScreen + 2 * cyFrame + cyCaption + cyMenu,
                    0);//SWP_NOOWNERZORDER
                //SetForegroundWindow

            }
            //else //��ǰ����ͨ״̬�������
            //{
            //    bRet = ::ShowWindow(hWnd,SW_SHOWMAXIMIZED);
            //}
        }
        else //�ָ�ԭ���ڴ�С
        {
            if(oldZoomedState)
            {
                //�Ƿ���ˣ�����
                bRet = SetWindowPos(hWnd,NULL,-cxFrame,-cyFrame,cxScreen + 2*cxFrame, cyScreen + 2*cyFrame, SWP_NOZORDER);
            }
            else
            {
                bRet = ShowWindow(hWnd,SW_RESTORE);
            }
        }
        return bRet;
    }

#if 0
    BOOL CFWinUtil::CenterWindow(HWND hWndCenter , BOOL bCurrMonitor)
    {
        FTLASSERT ( ::IsWindow ( m_hWnd ) ) ;
        // determine owner window to center against
        DWORD dwStyle = (DWORD)GetWindowLongPtr ( GWL_STYLE ) ;
        if ( NULL == hWndCenter )
        {
            if( dwStyle & WS_CHILD )
            {
                hWndCenter = ::GetParent ( m_hWnd ) ;
            }
            else
            {
                hWndCenter = ::GetWindow ( m_hWnd , GW_OWNER ) ;
            }
        }

        // Get coordinates of the window relative to its parent
        RECT rcDlg ;
        GetWindowRect ( &rcDlg ) ;
        RECT rcArea ;
        RECT rcCenter ;
        HWND hWndParent ;
        if ( !( dwStyle & WS_CHILD ) )
        {
            // Don't center against invisible or minimized windows
            if( NULL != hWndCenter )
            {
                DWORD dwStyle = ::GetWindowLongPtr ( hWndCenter ,
                    GWL_STYLE   ) ;
                if( !( dwStyle & WS_VISIBLE  ) ||
                    ( dwStyle & WS_MINIMIZE )   )
                {
                    hWndCenter = NULL ;
                }
            }

            if ( FALSE == bCurrMonitor )
            {
                // Center within screen coordinates
                ::SystemParametersInfo ( SPI_GETWORKAREA ,
                    NULL            ,
                    &rcArea         ,
                    NULL             ) ;
            }
            else
            {
                // Center based on the monitor containing the majority of
                // the window.
                HMONITOR hMon = MonitorFromWindow ( m_hWnd  ,
                    MONITOR_DEFAULTTONEAREST);

                MONITORINFO stMI ;
                ZeroMemory ( &stMI , sizeof ( MONITORINFO ) ) ;
                stMI.cbSize = sizeof ( MONITORINFO ) ;

                GetMonitorInfo ( hMon , &stMI ) ;

                rcArea = stMI.rcMonitor ;
            }

            if ( NULL == hWndCenter )
            {
                rcCenter = rcArea;
            }
            else
            {
                ::GetWindowRect ( hWndCenter , &rcCenter ) ;
            }
        }
        else
        {
            // center within parent client coordinates
            hWndParent = GetParent ( ) ;

            ::GetClientRect ( hWndParent , &rcArea ) ;

            ::GetClientRect ( hWndCenter , &rcCenter ) ;
            ::MapWindowPoints ( hWndCenter        ,
                hWndParent        ,
                (POINT*)&rcCenter ,
                2                  ) ;
        }

        int DlgWidth = rcDlg.right - rcDlg.left ;
        int DlgHeight = rcDlg.bottom - rcDlg.top ;

        // Find dialog's upper left based on rcCenter
        int xLeft = (rcCenter.left + rcCenter.right) / 2 - DlgWidth / 2 ;
        int yTop = (rcCenter.top + rcCenter.bottom) / 2 - DlgHeight / 2 ;

        // If the dialog is outside the screen, move it inside
        if ( xLeft < rcArea.left )
        {
            xLeft = rcArea.left ;
        }
        else if ( xLeft + DlgWidth > rcArea.right )
        {
            xLeft = rcArea.right - DlgWidth ;
        }

        if ( yTop < rcArea.top )
        {
            yTop = rcArea.top ;
        }
        else if ( yTop + DlgHeight > rcArea.bottom )
        {
            yTop = rcArea.bottom - DlgHeight ;
        }

        // Map screen coordinates to child coordinates
        return ( ::SetWindowPos ( m_hWnd ,
            NULL   ,
            xLeft  ,
            yTop   ,
            -1     ,
            -1     ,
            SWP_NOSIZE |
            SWP_NOZORDER |
            SWP_NOACTIVATE  ) ) ;

    }

#endif 

    BOOL CFWinUtil::ActiveAndForegroundWindow(HWND hWnd)
    {
        //IPMSG ��Ҳ��һ�� SetForceForegroundWindow ������������ͬ

        BOOL bRet = TRUE;
        HWND   hForegdWnd   =   ::GetForegroundWindow();
        if (hForegdWnd == hWnd)
        {
            return TRUE;
        }

        DWORD   dwCurID   =   ::GetCurrentThreadId();   
        DWORD   dwForeID   =   ::GetWindowThreadProcessId(hForegdWnd,NULL);
        if (dwCurID != dwForeID)
        {
            API_VERIFY(::AttachThreadInput(dwCurID,dwForeID,TRUE));

            //������ǰ��ֵ��Ȼ������Ϊ0
            DWORD sp_time = 0;
            SystemParametersInfo( SPI_GETFOREGROUNDLOCKTIMEOUT,0,&sp_time,0);
            SystemParametersInfo( SPI_SETFOREGROUNDLOCKTIMEOUT,0,(LPVOID)0,0);

            API_VERIFY(::SetForegroundWindow(hWnd));

            SystemParametersInfo( SPI_SETFOREGROUNDLOCKTIMEOUT,0,&sp_time,0);
            API_VERIFY(::AttachThreadInput(dwCurID,dwForeID,FALSE));
            //ShowWindow(hWnd,...)?
        }
        else
        {
            API_VERIFY(::SetForegroundWindow(hWnd));
            //ShowWindow(hWnd,...)?
        }
        SwitchToThisWindow(hWnd, TRUE);

//#pragma TODO(how to active a minimize window without change it min/max status)
//        if (IsIconic(hWnd))
//        {
//            API_VERIFY(ShowWindow(hWnd,SW_RESTORE));
//        }
//        else
//        {
//            API_VERIFY(ShowWindow(hWnd,SW_SHOW));
//        }

        return bRet;
    }

    LPCDLGTEMPLATE CFWinUtil::LoadDialog(HMODULE hModuleRes, LPCTSTR szResource, HINSTANCE * phInstFoundIn)
    {
        UNREFERENCED_PARAMETER(phInstFoundIn);
        // Find the dialog resource.
        HRSRC hRSRC = FindResourceEx ( hModuleRes ,RT_DIALOG,szResource,MAKELANGID ( LANG_NEUTRAL,SUBLANG_NEUTRAL )) ;
        if ( NULL == hRSRC )
        {
            return ( NULL ) ;
        }
        // Now load it.
        HGLOBAL hResource = LoadResource ( hModuleRes , hRSRC ) ;
        FTLASSERT ( NULL != hResource ) ;
        if ( NULL == hResource )
        {
            return ( NULL ) ;
        }
        LPCDLGTEMPLATE lpDlgTemplate = (LPCDLGTEMPLATE)LockResource ( hResource ) ;
        return lpDlgTemplate;
    }

    LPCTSTR CFWinUtil::GetScrollBarCodeString(UINT nSBCode)
    {
        switch(nSBCode)
        {
            HANDLE_CASE_RETURN_STRING((SB_LINEUP|SB_LINELEFT));
            HANDLE_CASE_RETURN_STRING((SB_LINEDOWN|SB_LINERIGHT));
            HANDLE_CASE_RETURN_STRING((SB_PAGEUP|SB_PAGELEFT));
            HANDLE_CASE_RETURN_STRING((SB_PAGEDOWN|SB_PAGERIGHT));
            HANDLE_CASE_RETURN_STRING(SB_THUMBPOSITION);
            HANDLE_CASE_RETURN_STRING(SB_THUMBTRACK);
            HANDLE_CASE_RETURN_STRING((SB_TOP|SB_LEFT));
            HANDLE_CASE_RETURN_STRING((SB_BOTTOM|SB_RIGHT));
            HANDLE_CASE_RETURN_STRING(SB_ENDSCROLL);
        default:
            FTLTRACEEX(FTL::tlWarning, TEXT("Unknown ScrollBar Code, %d\n"), nSBCode);
            return TEXT("Unknown");
        }
    }

    LPCTSTR CFWinUtil::GetNotifyCodeString(UINT nCode)
    {
        switch(nCode)
        {

            // generic to all controls
            HANDLE_CASE_RETURN_STRING(NM_FIRST);
            HANDLE_CASE_RETURN_STRING(NM_OUTOFMEMORY);
            HANDLE_CASE_RETURN_STRING(NM_CLICK);
            HANDLE_CASE_RETURN_STRING(NM_DBLCLK);
            HANDLE_CASE_RETURN_STRING(NM_RETURN);
            HANDLE_CASE_RETURN_STRING(NM_RCLICK);
            HANDLE_CASE_RETURN_STRING(NM_RDBLCLK);
            HANDLE_CASE_RETURN_STRING(NM_SETFOCUS);
            HANDLE_CASE_RETURN_STRING(NM_KILLFOCUS);
            HANDLE_CASE_RETURN_STRING(NM_CUSTOMDRAW);
            HANDLE_CASE_RETURN_STRING(NM_HOVER);
            HANDLE_CASE_RETURN_STRING(NM_NCHITTEST);
            HANDLE_CASE_RETURN_STRING(NM_KEYDOWN);
            HANDLE_CASE_RETURN_STRING(NM_RELEASEDCAPTURE);
            HANDLE_CASE_RETURN_STRING(NM_SETCURSOR);
            HANDLE_CASE_RETURN_STRING(NM_CHAR);
            HANDLE_CASE_RETURN_STRING(NM_TOOLTIPSCREATED);
#if (_WIN32_IE >= 0x0500)
            HANDLE_CASE_RETURN_STRING(NM_LDOWN);
            HANDLE_CASE_RETURN_STRING(NM_RDOWN);
            HANDLE_CASE_RETURN_STRING(NM_THEMECHANGED);
#endif

#if (_WIN32_WINNT >= 0x0600)
            HANDLE_CASE_RETURN_STRING(NM_FONTCHANGED);
            //HANDLE_CASE_RETURN_STRING(NM_CUSTOMTEXT);
            HANDLE_CASE_RETURN_STRING((NM_TVSTATEIMAGECHANGING | NM_CUSTOMTEXT)); //Same ID
#endif
            HANDLE_CASE_RETURN_STRING(NM_LAST);

            // listview
            HANDLE_CASE_RETURN_STRING(LVN_ITEMCHANGING);
            HANDLE_CASE_RETURN_STRING(LVN_ITEMCHANGED);
            HANDLE_CASE_RETURN_STRING(LVN_INSERTITEM);
            HANDLE_CASE_RETURN_STRING(LVN_DELETEITEM);
            HANDLE_CASE_RETURN_STRING(LVN_DELETEALLITEMS);
            HANDLE_CASE_RETURN_STRING(LVN_BEGINLABELEDITA);
            HANDLE_CASE_RETURN_STRING(LVN_BEGINLABELEDITW);
            HANDLE_CASE_RETURN_STRING(LVN_ENDLABELEDITA);
            HANDLE_CASE_RETURN_STRING(LVN_ENDLABELEDITW);
            HANDLE_CASE_RETURN_STRING(LVN_COLUMNCLICK);
            HANDLE_CASE_RETURN_STRING(LVN_BEGINDRAG);
            HANDLE_CASE_RETURN_STRING(LVN_BEGINRDRAG);
#if (_WIN32_IE >= 0x0300)
            HANDLE_CASE_RETURN_STRING(LVN_ODCACHEHINT);
            HANDLE_CASE_RETURN_STRING(LVN_ODFINDITEMA);
            HANDLE_CASE_RETURN_STRING(LVN_ODFINDITEMW);
            HANDLE_CASE_RETURN_STRING(LVN_ITEMACTIVATE);
            HANDLE_CASE_RETURN_STRING(LVN_ODSTATECHANGED);
#endif      // _WIN32_IE >= 0x0300


#if (_WIN32_IE >= 0x0400)
            HANDLE_CASE_RETURN_STRING(LVN_HOTTRACK);
#endif
            HANDLE_CASE_RETURN_STRING(LVN_GETDISPINFOA);
            HANDLE_CASE_RETURN_STRING(LVN_GETDISPINFOW);
            HANDLE_CASE_RETURN_STRING(LVN_SETDISPINFOA);
            HANDLE_CASE_RETURN_STRING(LVN_SETDISPINFOW);
            HANDLE_CASE_RETURN_STRING(LVN_KEYDOWN);
            HANDLE_CASE_RETURN_STRING(LVN_MARQUEEBEGIN);
            HANDLE_CASE_RETURN_STRING(LVN_GETINFOTIPA);
            HANDLE_CASE_RETURN_STRING(LVN_GETINFOTIPW);
#if (_WIN32_IE >= 0x0500)
#  ifndef LVN_INCREMENTALSEARCHA    
#    define LVN_INCREMENTALSEARCHA  (LVN_FIRST-62)
#  endif 
            HANDLE_CASE_RETURN_STRING(LVN_INCREMENTALSEARCHA);

#  ifndef LVN_INCREMENTALSEARCHW
#    define LVN_INCREMENTALSEARCHW  (LVN_FIRST-63)
#  endif 
            HANDLE_CASE_RETURN_STRING(LVN_INCREMENTALSEARCHW);
#endif //_WIN32_IE >= 0x0500 

#if _WIN32_WINNT >= 0x0600
            HANDLE_CASE_RETURN_STRING(LVN_COLUMNDROPDOWN);
            HANDLE_CASE_RETURN_STRING(LVN_COLUMNOVERFLOWCLICK);
#endif // _WIN32_WINNT >= 0x0600
#if (_WIN32_WINNT >= 0x0501)
            HANDLE_CASE_RETURN_STRING(LVN_BEGINSCROLL);
            HANDLE_CASE_RETURN_STRING(LVN_ENDSCROLL);
#endif
#if _WIN32_WINNT >= 0x0600
            HANDLE_CASE_RETURN_STRING(LVN_LINKCLICK);
            HANDLE_CASE_RETURN_STRING(LVN_GETEMPTYMARKUP);
#endif //_WIN32_WINNT >= 0x0600

            HANDLE_CASE_RETURN_STRING(LVN_LAST);

            // Property sheet reserved      (0U-200U) -  (0U-299U) - see prsht.h

            HANDLE_CASE_RETURN_STRING(PSN_SETACTIVE);
            HANDLE_CASE_RETURN_STRING(PSN_KILLACTIVE);  //PSN_VALIDATE
            HANDLE_CASE_RETURN_STRING(PSN_APPLY);
            HANDLE_CASE_RETURN_STRING(PSN_RESET);       //PSN_CANCEL
            HANDLE_CASE_RETURN_STRING(PSN_HELP);
            HANDLE_CASE_RETURN_STRING(PSN_WIZBACK);
            HANDLE_CASE_RETURN_STRING(PSN_WIZNEXT);
            HANDLE_CASE_RETURN_STRING(PSN_WIZFINISH);
            HANDLE_CASE_RETURN_STRING(PSN_QUERYCANCEL);
#if (_WIN32_IE >= 0x0400)
            HANDLE_CASE_RETURN_STRING(PSN_GETOBJECT);
#endif // 0x0400
#if (_WIN32_IE >= 0x0500)
            HANDLE_CASE_RETURN_STRING(PSN_TRANSLATEACCELERATOR);
            HANDLE_CASE_RETURN_STRING(PSN_QUERYINITIALFOCUS);
#endif // 0x0500

            // header
            HANDLE_CASE_RETURN_STRING(HDN_ITEMCHANGINGA);
            HANDLE_CASE_RETURN_STRING(HDN_ITEMCHANGINGW);
            HANDLE_CASE_RETURN_STRING(HDN_ITEMCHANGEDA);
            HANDLE_CASE_RETURN_STRING(HDN_ITEMCHANGEDW);
            HANDLE_CASE_RETURN_STRING(HDN_ITEMCLICKA);
            HANDLE_CASE_RETURN_STRING(HDN_ITEMCLICKW);
            HANDLE_CASE_RETURN_STRING(HDN_ITEMDBLCLICKA);
            HANDLE_CASE_RETURN_STRING(HDN_ITEMDBLCLICKW);
            HANDLE_CASE_RETURN_STRING(HDN_DIVIDERDBLCLICKA);
            HANDLE_CASE_RETURN_STRING(HDN_DIVIDERDBLCLICKW);
            HANDLE_CASE_RETURN_STRING(HDN_BEGINTRACKA);
            HANDLE_CASE_RETURN_STRING(HDN_BEGINTRACKW);
            HANDLE_CASE_RETURN_STRING(HDN_ENDTRACKA);
            HANDLE_CASE_RETURN_STRING(HDN_ENDTRACKW);
            HANDLE_CASE_RETURN_STRING(HDN_TRACKA);
            HANDLE_CASE_RETURN_STRING(HDN_TRACKW);
#if (_WIN32_IE >= 0x0300)
            HANDLE_CASE_RETURN_STRING(HDN_GETDISPINFOA);
            HANDLE_CASE_RETURN_STRING(HDN_GETDISPINFOW);
            HANDLE_CASE_RETURN_STRING(HDN_BEGINDRAG);
            HANDLE_CASE_RETURN_STRING(HDN_ENDDRAG);
#endif //_WIN32_IE
#if (_WIN32_IE >= 0x0500)
            HANDLE_CASE_RETURN_STRING(HDN_FILTERCHANGE);
            HANDLE_CASE_RETURN_STRING(HDN_FILTERBTNCLICK);
#endif //0x0500
#if (_WIN32_IE >= 0x0600)
            HANDLE_CASE_RETURN_STRING(HDN_BEGINFILTEREDIT);
            HANDLE_CASE_RETURN_STRING(HDN_ENDFILTEREDIT);
#endif
#if _WIN32_WINNT >= 0x0600
            HANDLE_CASE_RETURN_STRING(HDN_ITEMSTATEICONCLICK);
            HANDLE_CASE_RETURN_STRING(HDN_ITEMKEYDOWN);
            HANDLE_CASE_RETURN_STRING(HDN_DROPDOWN);
            HANDLE_CASE_RETURN_STRING(HDN_OVERFLOWCLICK);
#endif

            // treeview
            HANDLE_CASE_RETURN_STRING(TVN_SELCHANGINGA);
            HANDLE_CASE_RETURN_STRING(TVN_SELCHANGINGW);
            HANDLE_CASE_RETURN_STRING(TVN_SELCHANGEDA);
            HANDLE_CASE_RETURN_STRING(TVN_SELCHANGEDW);
            HANDLE_CASE_RETURN_STRING(TVN_GETDISPINFOA);
            HANDLE_CASE_RETURN_STRING(TVN_GETDISPINFOW);
            HANDLE_CASE_RETURN_STRING(TVN_SETDISPINFOA);
            HANDLE_CASE_RETURN_STRING(TVN_SETDISPINFOW);
            HANDLE_CASE_RETURN_STRING(TVN_ITEMEXPANDINGA);
            HANDLE_CASE_RETURN_STRING(TVN_ITEMEXPANDINGW);
            HANDLE_CASE_RETURN_STRING(TVN_ITEMEXPANDEDA);
            HANDLE_CASE_RETURN_STRING(TVN_ITEMEXPANDEDW);
            HANDLE_CASE_RETURN_STRING(TVN_BEGINDRAGA);
            HANDLE_CASE_RETURN_STRING(TVN_BEGINDRAGW);
            HANDLE_CASE_RETURN_STRING(TVN_BEGINRDRAGA);
            HANDLE_CASE_RETURN_STRING(TVN_BEGINRDRAGW);
            HANDLE_CASE_RETURN_STRING(TVN_DELETEITEMA);
            HANDLE_CASE_RETURN_STRING(TVN_DELETEITEMW);
            HANDLE_CASE_RETURN_STRING(TVN_BEGINLABELEDITA);
            HANDLE_CASE_RETURN_STRING(TVN_BEGINLABELEDITW);
            HANDLE_CASE_RETURN_STRING(TVN_ENDLABELEDITA);
            HANDLE_CASE_RETURN_STRING(TVN_ENDLABELEDITW);
            HANDLE_CASE_RETURN_STRING(TVN_KEYDOWN);
#if (_WIN32_IE >= 0x0400)
            HANDLE_CASE_RETURN_STRING(TVN_GETINFOTIPA);
            HANDLE_CASE_RETURN_STRING(TVN_GETINFOTIPW);
            HANDLE_CASE_RETURN_STRING(TVN_SINGLEEXPAND);
#endif // 0x400
#if (_WIN32_IE >= 0x0600)
            HANDLE_CASE_RETURN_STRING(TVN_ITEMCHANGINGA);
            HANDLE_CASE_RETURN_STRING(TVN_ITEMCHANGINGW);
            HANDLE_CASE_RETURN_STRING(TVN_ITEMCHANGEDA);
            HANDLE_CASE_RETURN_STRING(TVN_ITEMCHANGEDW);
            HANDLE_CASE_RETURN_STRING(TVN_ASYNCDRAW);
#endif // 0x0600

            //tooltips
            HANDLE_CASE_RETURN_STRING(TTN_GETDISPINFOA);
            HANDLE_CASE_RETURN_STRING(TTN_GETDISPINFOW);
            HANDLE_CASE_RETURN_STRING(TTN_SHOW);
            HANDLE_CASE_RETURN_STRING(TTN_POP);
            HANDLE_CASE_RETURN_STRING(TTN_LINKCLICK);

            //tab control
            HANDLE_CASE_RETURN_STRING(TCN_KEYDOWN);
            HANDLE_CASE_RETURN_STRING(TCN_SELCHANGE);
            HANDLE_CASE_RETURN_STRING(TCN_SELCHANGING);
#if (_WIN32_IE >= 0x0400)
            HANDLE_CASE_RETURN_STRING(TCN_GETOBJECT);
#endif      // _WIN32_IE >= 0x0400
#if (_WIN32_IE >= 0x0500)
            HANDLE_CASE_RETURN_STRING(TCN_FOCUSCHANGE);
#endif      // _WIN32_IE >= 0x0500


            // Shell reserved               (0U-580U) -  (0U-589U)

            // common dialog (new)

            // toolbar
            HANDLE_CASE_RETURN_STRING(TBN_GETBUTTONINFOA);
            HANDLE_CASE_RETURN_STRING(TBN_BEGINDRAG);
            HANDLE_CASE_RETURN_STRING(TBN_ENDDRAG);
            HANDLE_CASE_RETURN_STRING(TBN_BEGINADJUST);
            HANDLE_CASE_RETURN_STRING(TBN_ENDADJUST);
            HANDLE_CASE_RETURN_STRING(TBN_RESET);
            HANDLE_CASE_RETURN_STRING(TBN_QUERYINSERT);
            HANDLE_CASE_RETURN_STRING(TBN_QUERYDELETE);
            HANDLE_CASE_RETURN_STRING(TBN_TOOLBARCHANGE);
            HANDLE_CASE_RETURN_STRING(TBN_CUSTHELP);
#if (_WIN32_IE >= 0x0300)
            HANDLE_CASE_RETURN_STRING(TBN_DROPDOWN);
#endif //0x0300
#if (_WIN32_IE >= 0x0400)
            HANDLE_CASE_RETURN_STRING(TBN_GETOBJECT);
#endif //0x0400

            HANDLE_CASE_RETURN_STRING(TBN_HOTITEMCHANGE);
            HANDLE_CASE_RETURN_STRING(TBN_DRAGOUT);
            HANDLE_CASE_RETURN_STRING(TBN_DELETINGBUTTON);
            HANDLE_CASE_RETURN_STRING(TBN_GETDISPINFOA);
            HANDLE_CASE_RETURN_STRING(TBN_GETDISPINFOW);
            HANDLE_CASE_RETURN_STRING(TBN_GETINFOTIPA);
            HANDLE_CASE_RETURN_STRING(TBN_GETINFOTIPW);
            HANDLE_CASE_RETURN_STRING(TBN_GETBUTTONINFOW);
#if (_WIN32_IE >= 0x0500)
            HANDLE_CASE_RETURN_STRING(TBN_RESTORE);
            //HANDLE_CASE_RETURN_STRING(TBN_SAVE);
            HANDLE_CASE_RETURN_STRING(TBN_INITCUSTOMIZE);
#endif // (_WIN32_IE >= 0x0500)

            // updown
            HANDLE_CASE_RETURN_STRING(UDN_DELTAPOS); //ע�⣺UDN_DELTAPOS �� TBN_SAVE ��ֵһ����TBN_XXX ��ֵ������ TBN_LAST��

            // datetimepick
            HANDLE_CASE_RETURN_STRING(DTN_USERSTRINGA);
            HANDLE_CASE_RETURN_STRING(DTN_USERSTRINGW);
            HANDLE_CASE_RETURN_STRING(DTN_WMKEYDOWNA);
            HANDLE_CASE_RETURN_STRING(DTN_WMKEYDOWNW);
            HANDLE_CASE_RETURN_STRING(DTN_FORMATA);
            HANDLE_CASE_RETURN_STRING(DTN_FORMATW);
            HANDLE_CASE_RETURN_STRING(DTN_FORMATQUERYA);
            HANDLE_CASE_RETURN_STRING(DTN_FORMATQUERYW);

            // monthcal
            HANDLE_CASE_RETURN_STRING(MCN_SELCHANGE);
            HANDLE_CASE_RETURN_STRING(MCN_GETDAYSTATE);
            HANDLE_CASE_RETURN_STRING(MCN_SELECT);
            //HANDLE_CASE_RETURN_STRING(MCN_VIEWCHANGE);

            // datetimepick2
            HANDLE_CASE_RETURN_STRING(DTN_DATETIMECHANGE);
            HANDLE_CASE_RETURN_STRING(DTN_DROPDOWN);
            HANDLE_CASE_RETURN_STRING(DTN_CLOSEUP);

            // combo box ex
            HANDLE_CASE_RETURN_STRING(CBEN_GETDISPINFOA);
            HANDLE_CASE_RETURN_STRING(CBEN_INSERTITEM);
            HANDLE_CASE_RETURN_STRING(CBEN_DELETEITEM);
            HANDLE_CASE_RETURN_STRING(CBEN_BEGINEDIT);
            HANDLE_CASE_RETURN_STRING(CBEN_ENDEDITA);
            HANDLE_CASE_RETURN_STRING(CBEN_ENDEDITW);
            HANDLE_CASE_RETURN_STRING(CBEN_GETDISPINFOW);
            HANDLE_CASE_RETURN_STRING(CBEN_DRAGBEGINA);
            HANDLE_CASE_RETURN_STRING(CBEN_DRAGBEGINW);

            // rebar
            HANDLE_CASE_RETURN_STRING(RBN_HEIGHTCHANGE);
#if (_WIN32_IE >= 0x0400)
            HANDLE_CASE_RETURN_STRING(RBN_GETOBJECT);
            HANDLE_CASE_RETURN_STRING(RBN_LAYOUTCHANGED);
            HANDLE_CASE_RETURN_STRING(RBN_AUTOSIZE);
            HANDLE_CASE_RETURN_STRING(RBN_BEGINDRAG);
            HANDLE_CASE_RETURN_STRING(RBN_ENDDRAG);
            HANDLE_CASE_RETURN_STRING(RBN_DELETINGBAND);
            HANDLE_CASE_RETURN_STRING(RBN_DELETEDBAND);
            HANDLE_CASE_RETURN_STRING(RBN_CHILDSIZE);
#if (_WIN32_IE >= 0x0500)
            HANDLE_CASE_RETURN_STRING(RBN_CHEVRONPUSHED);
#endif      // _WIN32_IE >= 0x0500
#if (_WIN32_IE >= 0x0600)
            HANDLE_CASE_RETURN_STRING(RBN_SPLITTERDRAG);
#endif      // _WIN32_IE >= 0x0600
#if (_WIN32_IE >= 0x0500)
            HANDLE_CASE_RETURN_STRING(RBN_MINMAX);
#endif      // _WIN32_IE >= 0x0500
#if (_WIN32_WINNT >= 0x0501)
            HANDLE_CASE_RETURN_STRING(RBN_AUTOBREAK);
#endif //0x0501
#endif //0x0400


#if (_WIN32_IE >= 0x0400)
            // internet address
            HANDLE_CASE_RETURN_STRING(IPN_FIELDCHANGED);

            // status bar
            HANDLE_CASE_RETURN_STRING(SBN_SIMPLEMODECHANGE);

            // Pager Control
            HANDLE_CASE_RETURN_STRING(PGN_SCROLL);
            HANDLE_CASE_RETURN_STRING(PGN_CALCSIZE);
            HANDLE_CASE_RETURN_STRING(PGN_HOTITEMCHANGE);
#endif //_WIN32_IE >= 0x0400

#if (_WIN32_IE >= 0x0500)
            //WMN_FIRST
#endif //_WIN32_IE >= 0x0500

#if (_WIN32_WINNT >= 0x0501)
            //BCN_FIRST
#  ifndef NM_GETCUSTOMSPLITRECT
#    define NM_GETCUSTOMSPLITRECT       (BCN_FIRST + 0x0003)
#  endif
            HANDLE_CASE_RETURN_STRING(NM_GETCUSTOMSPLITRECT);
            HANDLE_CASE_RETURN_STRING(BCN_HOTITEMCHANGE);
#endif //_WIN32_WINNT >= 0x0501

#if (_WIN32_WINNT >= 0x600)
            HANDLE_CASE_RETURN_STRING(BCN_DROPDOWN);
#endif // _WIN32_WINNT >= 0x600


#if (_WIN32_WINNT >= 0x0600)
            // trackbar
            HANDLE_CASE_RETURN_STRING(TRBN_THUMBPOSCHANGING);
#endif //_WIN32_WINNT >= 0x0600
        }

        FTLTRACEEX(FTL::tlWarning, TEXT("Unknown Notify Code, %d\n"), nCode);
        return TEXT("Unknown");
    }

    LPCTSTR CFWinUtil::GetCommandNotifyString(HWND hWnd, UINT nCode)
    {
        TCHAR szClassName[MAX_PATH] = {0};
        switch(nCode)
        {
            //Combo Box Notification Codes
            HANDLE_CASE_RETURN_STRING(CBN_ERRSPACE);
            HANDLE_CASE_RETURN_STRING(CBN_SELCHANGE);
            HANDLE_CASE_RETURN_STRING(CBN_DBLCLK);
            HANDLE_CASE_RETURN_STRING(CBN_SETFOCUS);
            HANDLE_CASE_RETURN_STRING(CBN_KILLFOCUS);
            HANDLE_CASE_RETURN_STRING(CBN_EDITCHANGE);
            HANDLE_CASE_RETURN_STRING(CBN_EDITUPDATE);
            HANDLE_CASE_RETURN_STRING(CBN_DROPDOWN);
            HANDLE_CASE_RETURN_STRING(CBN_CLOSEUP);
            HANDLE_CASE_RETURN_STRING(CBN_SELENDOK);
            HANDLE_CASE_RETURN_STRING(CBN_SELENDCANCEL);
        default:
            FTLTRACEEX(FTL::tlWarning, TEXT("Unknown Command Code, %d\n"), nCode);
            FTLASSERT(FALSE);
            return TEXT("Unknown");
        }
    }


    LPCTSTR CFWinUtil::GetWindowStyleString(FTL::CFStringFormater& formater, HWND hWnd,LPCTSTR pszDivide/* = TEXT("|") */)
    {
        BOOL bRet = FALSE;

        FTLASSERT(::IsWindow(hWnd));
        LONG_PTR    lStyle = ::GetWindowLongPtr(hWnd, GWL_STYLE);
        LONG_PTR    lOldStyle = lStyle;
        //HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_OVERLAPPED, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_POPUP, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_CHILDWINDOW, pszDivide); //WS_CHILD
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_MINIMIZE, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_VISIBLE, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_DISABLED, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_CLIPSIBLINGS, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_CLIPCHILDREN, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_MAXIMIZE, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_CAPTION, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_BORDER, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_DLGFRAME, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_VSCROLL, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_HSCROLL, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_SYSMENU, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_THICKFRAME, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_GROUP, pszDivide);      //WS_MINIMIZEBOX
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, WS_TABSTOP, pszDivide);    //WS_MAXIMIZEBOX

        //ͨ�õ����Ͷ����� 0x00010000L�� ���ֱ�׼�ؼ����е� Style С�� 0x00010000L

        TCHAR szClassName[256+1] = {0}; //The maximum length for lpszClassName is 256.
        API_VERIFY(0 != ::GetClassName(hWnd, szClassName, _countof(szClassName)));
        
        //BUTTON
        if (0 ==  lstrcmpi(szClassName, WC_BUTTON))
        {
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_LEFTTEXT, pszDivide);

			if (0 != (lStyle & BS_TYPEMASK))
			{
#if _WIN32_WINNT >= 0x0600
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_DEFCOMMANDLINK, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_COMMANDLINK, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_DEFSPLITBUTTON, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_SPLITBUTTON, pszDivide);
#endif //_WIN32_WINNT >= 0x0600
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_OWNERDRAW, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_PUSHBOX, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_AUTORADIOBUTTON, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_USERBUTTON, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_GROUPBOX, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_AUTO3STATE, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_3STATE, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_RADIOBUTTON, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_AUTOCHECKBOX, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_CHECKBOX, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_DEFPUSHBUTTON, pszDivide);
			}
			else
			{
				//HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_PUSHBUTTON, pszDivide);
				formater.AppendFormat(TEXT("%s%s"), TEXT("BS_PUSHBUTTON"), pszDivide);
			}

            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_FLAT, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_NOTIFY, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_MULTILINE, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_PUSHLIKE, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_VCENTER, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_BOTTOM, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_TOP, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_CENTER, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_RIGHT, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_LEFT, pszDivide);

			if ( 0 != (lStyle & (BS_ICON|BS_TEXT)))
			{
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_BITMAP, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_ICON, pszDivide);
			}
			else
			{
				//HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, BS_TEXT, pszDivide);
				formater.AppendFormat(TEXT("%s%s"), TEXT("BS_TEXT"), pszDivide);
			}
        }

		//Combo Box styles
		if (0 ==  lstrcmp(szClassName, WC_COMBOBOX))
		{
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_DROPDOWNLIST, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_DROPDOWN, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_SIMPLE, pszDivide);

			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_OWNERDRAWFIXED, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_OWNERDRAWVARIABLE, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_AUTOHSCROLL, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_OEMCONVERT, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_SORT, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_HASSTRINGS, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_NOINTEGRALHEIGHT, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_DISABLENOSCROLL, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_UPPERCASE, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, CBS_LOWERCASE, pszDivide);
		}

		//Edit Control Styles
		if (0 ==  lstrcmp(szClassName, WC_EDIT))
		{
			#define ES_ALIGNMASK	(ES_LEFT | ES_CENTER | ES_RIGHT)
			if ( 0 != (lStyle & ES_ALIGNMASK))
			{
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_RIGHT, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_CENTER, pszDivide);
			}
			else
			{
				//HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_LEFT, pszDivide);
				formater.AppendFormat(TEXT("%s%s"), TEXT("ES_LEFT"), pszDivide);
			}

			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_MULTILINE, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_UPPERCASE, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_LOWERCASE, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_PASSWORD, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_AUTOVSCROLL, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_AUTOHSCROLL, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_NOHIDESEL, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_OEMCONVERT, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_READONLY, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_WANTRETURN, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, ES_NUMBER, pszDivide);
		}

        //ListView
        if (0 ==  lstrcmp(szClassName, WC_LISTVIEW))
        {
			if (0 != (lStyle & LVS_TYPEMASK))
			{
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_LIST, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_SMALLICON, pszDivide);
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_REPORT, pszDivide);
			}
			else
			{
				//HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_ICON, pszDivide);
				formater.AppendFormat(TEXT("%s%s"), TEXT("LVS_ICON"), pszDivide);
			}

			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_SINGLESEL, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_SHOWSELALWAYS, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_SORTASCENDING, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_SORTDESCENDING, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_SHAREIMAGELISTS, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_NOLABELWRAP, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_AUTOARRANGE, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_EDITLABELS, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_OWNERDATA, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_NOSCROLL, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_TYPESTYLEMASK, pszDivide);

			if (0 != (lStyle & LVS_ALIGNMASK ))
			{
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_ALIGNLEFT, pszDivide);
			}
			else
			{
				//HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_ALIGNTOP, pszDivide);
				formater.AppendFormat(TEXT("%s%s"), TEXT("LVS_ALIGNTOP"), pszDivide);
			}

			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_NOSORTHEADER, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_NOCOLUMNHEADER, pszDivide);
            HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, LVS_OWNERDRAWFIXED, pszDivide);
        }

		//Scroll Bar Styles
		if (0 ==  lstrcmp(szClassName, WC_SCROLLBAR))
		{
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, SBS_SIZEGRIP, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, SBS_SIZEBOX, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, SBS_BOTTOMALIGN|SBS_RIGHTALIGN|SBS_SIZEBOXBOTTOMRIGHTALIGN, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, SBS_TOPALIGN|SBS_LEFTALIGN|SBS_SIZEBOXTOPLEFTALIGN, pszDivide);
			if (0 != (lStyle & SBS_VERT))
			{
				HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, SBS_VERT, pszDivide);
			}
			else
			{
				//HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, SBS_HORZ, pszDivide);
				formater.AppendFormat(TEXT("%s%s"), TEXT("SBS_HORZ"), pszDivide);
			}
		}

		//SysHeader32 Box styles
		if (0 ==  lstrcmp(szClassName, WC_HEADER))
		{
			//HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, HDS_HORZ, pszDivide);
			formater.AppendFormat(TEXT("%s%s"), TEXT("HDS_HORZ"), pszDivide);

			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, HDS_BUTTONS, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, HDS_HOTTRACK, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, HDS_HIDDEN, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, HDS_DRAGDROP, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, HDS_FULLDRAG, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, HDS_FILTERBAR, pszDivide);
#if (_WIN32_WINNT >= 0x0501)
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, HDS_FLAT, pszDivide);
#endif //_WIN32_WINNT >= 0x0501
#if _WIN32_WINNT >= 0x0600
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, HDS_CHECKBOXES, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, HDS_NOSIZING, pszDivide);
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, HDS_OVERFLOW, pszDivide);
#endif
		}

        FTLASSERT( 0 == lStyle);
		//HANDLE_COMBINATION_VALUE_TO_STRING(formater, lStyle, XXXXXXXXX, pszDivide);
        if (0 != lStyle)
        {
            FTLTRACEEX(FTL::tlWarning, TEXT("%s:Check Style String For \"%s\" Not Complete, total=0x%08x, remain=0x%08x\n"),
                __FILE__LINE__, szClassName, lOldStyle, lStyle);
        }
        return formater.GetString();
    }

    LPCTSTR CFWinUtil::GetWindowExStyleString(FTL::CFStringFormater& formater, HWND hWnd, LPCTSTR pszDivide /* = TEXT */)
    {
        FTLASSERT(::IsWindow(hWnd));
        LONG_PTR    lExStyle = ::GetWindowLongPtr(hWnd, GWL_EXSTYLE);
        LONG_PTR    lOldExStyle = lExStyle;

        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_DLGMODALFRAME, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_NOPARENTNOTIFY, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_TOPMOST, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_ACCEPTFILES, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_TRANSPARENT, pszDivide);  //���ᴩ͸�˴���(����Ӱ)
#if(WINVER >= 0x0400)
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_MDICHILD, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_TOOLWINDOW, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_WINDOWEDGE, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_CLIENTEDGE, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_CONTEXTHELP, pszDivide);
		if (0 != (lExStyle & WS_EX_RIGHT) )
		{
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_RIGHT, pszDivide);
		}
		else
		{
			//HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_LEFT, pszDivide);
			formater.AppendFormat(TEXT("%s%s"), TEXT("WS_EX_LEFT"), pszDivide);
		}
		if (0 != (lExStyle & WS_EX_RTLREADING))
		{
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_RTLREADING, pszDivide);
		}
		else
		{
			//HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_LTRREADING, pszDivide);
			formater.AppendFormat(TEXT("%s%s"), TEXT("WS_EX_LTRREADING"), pszDivide);
		}
		if (0 != (lExStyle & WS_EX_LEFTSCROLLBAR))
		{
			HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_LEFTSCROLLBAR, pszDivide);
		}
		else
		{
			//HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_RIGHTSCROLLBAR, pszDivide);
			formater.AppendFormat(TEXT("%s%s"), TEXT("WS_EX_RIGHTSCROLLBAR"), pszDivide);
		}
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_CONTROLPARENT, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_STATICEDGE, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_APPWINDOW, pszDivide);
#endif /* WINVER >= 0x0400 */

#if(_WIN32_WINNT >= 0x0500)
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_LAYERED, pszDivide);
#endif /* _WIN32_WINNT >= 0x0500 */

#if(WINVER >= 0x0500)
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_NOINHERITLAYOUT, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_LAYOUTRTL, pszDivide);
#endif /* WINVER >= 0x0500 */

#if(_WIN32_WINNT >= 0x0501)
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_COMPOSITED, pszDivide);
#endif /* _WIN32_WINNT >= 0x0501 */

#if(_WIN32_WINNT >= 0x0500)
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, lExStyle, WS_EX_NOACTIVATE, pszDivide);
#endif /* _WIN32_WINNT >= 0x0500 */

        FTLASSERT( 0 == lExStyle);
        if (0 != lExStyle)
        {
            FTLTRACEEX(FTL::tlWarning, TEXT("%s: Check ExStyle String Not Complete, total=0x%08x, remain=0x%08x\n"),
                __FILE__LINE__, lOldExStyle, lExStyle);
        }
        return formater.GetString();
    }

	LPCTSTR CFWinUtil::GetOwnerDrawState(FTL::CFStringFormater& formater, UINT itemState, LPCTSTR pszDivide)
	{
		UINT    oldItemState = itemState;

		HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemState, ODS_SELECTED, pszDivide);
		HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemState, ODS_GRAYED, pszDivide);
		HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemState, ODS_DISABLED, pszDivide);
		HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemState, ODS_CHECKED, pszDivide);
		HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemState, ODS_FOCUS, pszDivide);
		HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemState, ODS_DEFAULT, pszDivide);
		HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemState, ODS_COMBOBOXEDIT, pszDivide);
#if(WINVER >= 0x0500)
		HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemState, ODS_HOTLIGHT, pszDivide);
		HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemState, ODS_INACTIVE, pszDivide);
#if(_WIN32_WINNT >= 0x0500)
		HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemState, ODS_NOACCEL, pszDivide);
		HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemState, ODS_NOFOCUSRECT, pszDivide);
#endif /* _WIN32_WINNT >= 0x0500 */
#endif /* WINVER >= 0x0500 */

		FTLASSERT( 0 == itemState);
		if (0 != itemState)
		{
			FTLTRACEEX(FTL::tlWarning, TEXT("%s: GetOwnerDrawState Not Complete, total=0x%08x, remain=0x%08x\n"),
				__FILE__LINE__, oldItemState, itemState);
		}
		return formater.GetString();
	}


    LPCTSTR CFWinUtil::GetOwnerDrawAction(FTL::CFStringFormater& formater, UINT itemAction, LPCTSTR pszDivide)
    {
        //UINT    oldItemAction = itemAction;

        HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemAction, ODA_DRAWENTIRE, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemAction, ODA_SELECT, pszDivide);
        HANDLE_COMBINATION_VALUE_TO_STRING(formater, itemAction, ODA_FOCUS, pszDivide);

        FTLASSERT(0 == itemAction);
        return formater.GetString();
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////

    __declspec(selectany) HHOOK CFMessageBoxHook::s_hHook = NULL;
    __declspec(selectany) HWND  CFMessageBoxHook::s_ProphWnd = NULL;
    __declspec(selectany) LPCTSTR CFMessageBoxHook::s_pszOKString = NULL;

    CFMessageBoxHook::CFMessageBoxHook(DWORD dwThreadId, LPCTSTR pszOKString)
    {
        BOOL bRet = FALSE;
        CFMessageBoxHook::s_pszOKString = pszOKString;
        s_hHook = ::SetWindowsHookEx(WH_CBT, (HOOKPROC)CFMessageBoxHook::CBTProc
            , NULL, dwThreadId);
        API_VERIFY(NULL != s_hHook);
    }

    CFMessageBoxHook::~CFMessageBoxHook(void)
    {
        if (CFMessageBoxHook::s_ProphWnd)
        {
            RemoveProp(CFMessageBoxHook::s_ProphWnd,PREV_WND_PROC_NAME);
            CFMessageBoxHook::s_ProphWnd = NULL;
        }
        if (CFMessageBoxHook::s_hHook)
        {
            ::UnhookWindowsHookEx(CFMessageBoxHook::s_hHook);
            CFMessageBoxHook::s_hHook = NULL;
        }
    }


    LRESULT CFMessageBoxHook::CBTProc(int nCode, WPARAM wParam, LPARAM lParam)
    {
        if (NULL == CFMessageBoxHook::s_hHook)
            return 0;
        BOOL bRet = FALSE;

        if (nCode == HCBT_CREATEWND){ //HCBT_CREATEWND = 3
            HWND hWnd = (HWND)wParam;
            TCHAR className[MAX_PATH];
            ::GetClassName(hWnd, className, _countof(className));
            if (_tcscmp(className, _T("#32770")) == 0)
            {
                WNDPROC prevWndProc = (WNDPROC)::SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)CFMessageBoxHook::WndProc);
                API_VERIFY(::SetProp(hWnd, PREV_WND_PROC_NAME, (HANDLE)prevWndProc));
                if (bRet)
                {
                    CFMessageBoxHook::s_ProphWnd = hWnd;
                }
            }
        }
        return ::CallNextHookEx(s_hHook, nCode, wParam, lParam);
    }

    LRESULT CFMessageBoxHook::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        WNDPROC prevWndProc = (WNDPROC)::GetProp(hWnd, PREV_WND_PROC_NAME);
        FTLASSERT(prevWndProc != NULL);

        if (message == WM_INITDIALOG)
        {
            BOOL bRet = FALSE;
            API_VERIFY(SetDlgItemText(hWnd, IDOK, CFMessageBoxHook::s_pszOKString));
        }
        return ::CallWindowProc(prevWndProc, hWnd, message, wParam, lParam);
    }

#if 0
    template <typename ControlT , typename ConverterFun>
    CControlPropertyHandleT<ControlT, ConverterFun>::
        CControlPropertyHandleT(ControlT& control)//, ConverterFun& fun)
        :m_control(control)
        //,m_fun(fun)
    {
    }

    template <typename ControlT , typename ConverterFun>
    INT CControlPropertyHandleT<ControlT, ConverterFun>::AddProperty(INT value)
    {
        INT index = m_control.AddString(ConverterFun(value));
        m_control.SetItemData(value);
        return index;
    }

#endif


}//FTL


#endif //FTL_WINDOW_HPP