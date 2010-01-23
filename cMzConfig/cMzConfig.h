#pragma once
/*
 * @filename appconfigini.h
 * @note Ӧ�ó��������ļ���д��
 * @author JEMYZHANG
 * @date 2009.6.20
 * @ver. 1.1
 * @changelog
 *  ver.1.0 ��ʼ������
 *  ver.1.1 ����cMzConfig�࣬�򻯼�ֵ��д
 *  ver.1.2 cMzConfig�ڽ⹹ʱ��д�����ã��������õ��ļ���д
*/

#include <cMzCommonDll.h>

//�����ļ�·��
//��AppConfigIni��ʼ��
static TCHAR * gs_inifile = NULL;

//�����ļ�������д��
class COMMON_API cMzConfig{
public:
	cMzConfig(){
		_mainKey = NULL;
		_subKey = NULL;
		_defaultValue = 0;
		_value = 0;
		_bupdate = false;
	}
	~cMzConfig();
public:
	void InitKey(TCHAR * mainKey, TCHAR * subKey, DWORD defaultVal = 0);
public:
	DWORD Get() { return _value; }
	BOOL Set(DWORD v) { 
		if(_value == v) return FALSE;
		_value = v; 
		_bupdate = true;
		return TRUE;
	}
private:
	//��������ļ�·���Լ���ֵ
	bool checkKey(){
		bool nRet = true;
		if(_mainKey == NULL || _subKey == NULL ||
			gs_inifile == NULL){
			nRet = false;
		}
		return nRet;
	}
private:
	TCHAR * _mainKey;	//����
	TCHAR * _subKey;	//�Ӽ�
	DWORD _defaultValue;	//����ֵ������ʱ��Ĭ��ֵ
	DWORD _value;	//ֵ
	bool _bupdate;	//����ֵ�����Ҫ����
};

/////////////////////////////////
//Ӧ�ó�������
class COMMON_API AppConfigIni
{
public:
	AppConfigIni(LPTSTR iniFile = NULL){
		SetupIniPath(iniFile);
		CreateIni();
		InitIniKey();
	}
protected:
	void SetupIniPath(LPTSTR iniFile = NULL);
	void CreateIni();
	virtual void InitIniKey();
public:
	//config�汾��Ϣ
	cMzConfig IniConfigVersion;
private:
	wchar_t ini_path[MAX_PATH];
};