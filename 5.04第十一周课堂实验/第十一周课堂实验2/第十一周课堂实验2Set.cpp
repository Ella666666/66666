
// ��ʮһ�ܿ���ʵ��2Set.cpp : C��ʮһ�ܿ���ʵ��2Set ���ʵ��
//

#include "stdafx.h"
#include "��ʮһ�ܿ���ʵ��2.h"
#include "��ʮһ�ܿ���ʵ��2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮһ�ܿ���ʵ��2Set ʵ��

// ���������� 2020��5��25��, 19:11

IMPLEMENT_DYNAMIC(C��ʮһ�ܿ���ʵ��2Set, CRecordset)

C��ʮһ�ܿ���ʵ��2Set::C��ʮһ�ܿ���ʵ��2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C��ʮһ�ܿ���ʵ��2Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f\x8868;DBQ=C:\\\x5927\x4e8c\x4e0b\\\x5b9e\x9a8c\\\x5b66\x751f\x4fe1\x606f\x8868.xls;DefaultDir=C:\\\x5927\x4e8c\x4e0b\\\x5b9e\x9a8c;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString C��ʮһ�ܿ���ʵ��2Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void C��ʮһ�ܿ���ʵ��2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);

}
/////////////////////////////////////////////////////////////////////////////
// C��ʮһ�ܿ���ʵ��2Set ���

#ifdef _DEBUG
void C��ʮһ�ܿ���ʵ��2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C��ʮһ�ܿ���ʵ��2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

