#ifndef FTL_REG_H
#define FTL_REG_H
#pragma once

#ifndef FTL_BASE_H
#  error ftlReg.h requires ftlbase.h to be included first
#endif

#include "ftlFile.h"
/*************************************************************************************************************************
*************************************************************************************************************************/


namespace FTL
{
    enum RegExportFlags
    {
        WRITE_PATH_NONE     = 0x0000,
        WRITE_PATH_AUTO     = 0x0001,       //���� pszValueName Ϊ *ʱ
        
        EXPORT_SUB_KEY       = 0x0010,
        EXPORT_MULTI_VALUE   = 0x0020,
    };

    class CFRegUtil
    {
    public:
        FTLINLINE static LPCTSTR ConvertRegRootKeyToString(HKEY hKeyRoot);
        FTLINLINE static HKEY ConvertStringToRegRootKey(LPCTSTR pszKeyRoot);

        //RegNotifyChangeKeyValue -- ���ע����ı仯�����Կ�����Ӧ
        //RegCreateKeyEx -- ����ע����������ڵĻ����
        //RegQueryValueEx -- ��ȡ �ַ���(REG_SZ)��DWORD(REG_DWORD) ע����� ���� ��ֵ
        //RegSetValueEx -- ����ֵ�����lpSubKeyΪNULL��""��������Ĭ��ֵ
        //RegOpenKeyEx -- ��ע���
        //RegEnumKeyEx -- ö���Ӽ���������ɾ���������Ӽ��ȣ�û�и���ʱ���� ERROR_NO_MORE_ITEMS
        //RegDeleteKey -- ɾ��û���¼��Ӽ����Ӽ�,���Ҫ�ݹ�ɾ��������ʹ�� CRegKey::RecurseDeleteKey 
        //RegSaveKey/RegSaveKeyEx -- �Զ����Ʒ�ʽ����ע�������
        FTLINLINE static LONG GetRegValueExportString(HKEY hKey, LPCTSTR pszValueName, CAtlString& strResult, DWORD* pRegType);

        //�� .reg ���ı���ʽ ����ע���������
        //  ע�⣺���ܲ��� CRegKey �����෽ʽʵ��(����m_hKey) -- ��û�б���ע���·��
        FTLINLINE static LONG ExportRegValueToFile(LPCTSTR pszFullKey, 
            LPCTSTR pszValueName, 
            CFUnicodeFile* pRegFile, 
            DWORD flags = EXPORT_SUB_KEY | EXPORT_MULTI_VALUE,
            REGSAM samDesired = KEY_READ | KEY_ENUMERATE_SUB_KEYS | KEY_QUERY_VALUE);

        //FTLINLINE static LONG EnumRegKeyHandle(HKEY hKey, )
    };

    class IRegSerializeCallback
    {
    public:
        //TODO
    };
    class CFRegSerialize
    {
    public:
        FTLINLINE CFRegSerialize();
        FTLINLINE ~CFRegSerialize();
        FTLINLINE LONG CreateRegFile(LPCTSTR pszFilePath);
        FTLINLINE LONG CloseRegFile();

        FTLINLINE LONG ExportReg(LPCTSTR pszFullKey, LPCTSTR pszValueName = _T("*"), 
            DWORD flags = EXPORT_SUB_KEY | EXPORT_MULTI_VALUE,
            REGSAM samDesired = KEY_READ | KEY_ENUMERATE_SUB_KEYS | KEY_QUERY_VALUE);
        
    protected:
        FTLINLINE LONG _ExportReg(HKEY hKeyRoot, LPCTSTR pszSubKey, LPCTSTR pszValueName, DWORD flags, REGSAM samDesired);
        FTLINLINE LONG _ExportReg(HKEY hKey, LPCTSTR pszValueName);
        FTLINLINE LONG _ConstructExportString(CAtlString& strRegExport, LPCTSTR pszValueName, 
            const CAtlString& strValueResult, DWORD regType);
        BOOL _LineWrapperBinaryString(CAtlString& strRegExport, INT nValueLen, DWORD regType);

        FTLINLINE BOOL _WillExportMultiValue(LPCTSTR pszValueName, DWORD flags);

        volatile BOOL  m_bWillQuit;
        CAtlString  m_strRootKey;
        //CAtlString  m_strSubKey;
        CFUnicodeFile* m_pRegFile;
    };
}
#endif //FTL_REG_H

#ifndef USE_EXPORT
#  include "ftlReg.hpp"
#endif 