
// �ۺ�ʵ��2Set.cpp : C�ۺ�ʵ��2Set ���ʵ��
//

#include "stdafx.h"
#include "�ۺ�ʵ��2.h"
#include "�ۺ�ʵ��2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ��2Set ʵ��

// ���������� 2020��5��26��, 21:57

IMPLEMENT_DYNAMIC(C�ۺ�ʵ��2Set, CRecordset)

C�ۺ�ʵ��2Set::C�ۺ�ʵ��2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C�ۺ�ʵ��2Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f\x8868\x516d;DBQ=C:\\\x5927\x4e8c\x4e0b\\\x5b9e\x9a8c\\\x5b66\x751f\x4fe1\x606f\x8868\x516d.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C�ۺ�ʵ��2Set::GetDefaultSQL()
{
	return _T("[��1]");
}

void C�ۺ�ʵ��2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// C�ۺ�ʵ��2Set ���

#ifdef _DEBUG
void C�ۺ�ʵ��2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C�ۺ�ʵ��2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

