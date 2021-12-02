//WinMain.cpp
// window Ӧ�ó��򣬶��ַ���
#include<windows.h>
#include <Windowsx.h>
#include"GameApp.h"


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE hIns = 0;  //ȫ�ֱ���������ʵ�����

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//-----------------------------------------------------
	HWND hwnd = 0;
	MSG msg;       //  װ��Ϣ�Ľṹ��
	WNDCLASSEX wndclass;
	//-----------------------------------------------------

	hIns = hInstance;
	LPCSTR lClassName = "yue"; //��������
	extern int nx;                  //����λ��X
	extern int ny;                  //����λ��Y
	extern int nwidth;              //���ڿ��
	extern int nheigh;              //���ڸ߶�
	extern CHAR * strTitle;         //���ڱ�����
	int pos_x=nx;
	if(pos_x<0){
		pos_x=0;
	}
	int pos_y=ny;
	if(pos_y<0){
		pos_y=0;
	}
	int nWidth=nwidth;
	if(nWidth<=0){
		nWidth = 500;
	}
	int nHeight=nheigh;
	if(nHeight<=0){
		nHeight = 500;
	}

	//----------------------�������ڹ���-----------------------------------
	//  1. ���
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wndclass.hCursor = LoadCursor(0, MAKEINTRESOURCE(IDC_ARROW));
	wndclass.hIcon = 0;
	wndclass.hIconSm = 0;
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WindowProc;
	wndclass.lpszClassName = lClassName;
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	// 2.  ע��
	if (RegisterClassEx(&wndclass) == FALSE)
	{
		MessageBox(0, "ע��ʧ��", "��ʾ", MB_OK);
		return 0;
	}
	//  3.  ����
	hwnd = CreateWindow(lClassName, strTitle, WS_OVERLAPPEDWINDOW, pos_x, pos_y, nWidth, nHeight, 0, 0, hInstance, 0);
	if (hwnd == 0)
	{
		MessageBox(0, "����ʧ��", "��ʾ", MB_OK);
		return 0;
	}
	//  4.  ��ʾ����
	ShowWindow(hwnd, SW_SHOW);
	//---------------------------�������ڹ���------------------------------------------------

	//----------------------------��Ϣѭ��-------------------------------------------
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//----------------------------��Ϣѭ��-------------------------------------------

	return 0;
}
CGameApp *pGameApp = NULL;
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE: //���ڴ�����Ϣ
	{
		if(pGameApp == NULL){
			//pGameApp = new CAA;
			pGameApp = GetChildObject();

			pGameApp->SetHandle(hIns,hWnd);
			pGameApp->OnCreate();
		}
	}
	break;
	case WM_PAINT:  //�ػ���Ϣ
	{
		if(pGameApp){
			pGameApp->OnDraw();
		}
	}
	break;
	case WM_TIMER:   //��ʱ������Ҫ�������������ֶ���Ӷ�ʱ�������ô������
	{
		if(pGameApp){
			pGameApp->OnGameRun(wParam);
		}
	}
	break;
	case WM_KEYDOWN:  //���̰��´�����Ϣ
	{
		if(pGameApp){
			pGameApp->OnKeyDown(wParam);
		}
	}
	break;
	case WM_KEYUP:  //����̧�𴥷���Ϣ
	{
		if(pGameApp){
			pGameApp->OnKeyUp(wParam);
		}
	}
	break;
	case WM_LBUTTONDOWN: //���������´�����Ϣ
	{
		if(pGameApp){
			POINT po={0};
			po.x = GET_X_LPARAM(lParam); 
			po.y = GET_Y_LPARAM(lParam);
			pGameApp->OnLButtonDown(po);
		}
	}
	break;
	case WM_LBUTTONUP: //������̧�𴥷���Ϣ
	{
		if(pGameApp){
			POINT po={0};
			po.x = GET_X_LPARAM(lParam); 
			po.y = GET_Y_LPARAM(lParam);
			pGameApp->OnLButtonUp(po);
		}
	}
	break;
	case WM_MOUSEMOVE:  //����ƶ�
	{
		if(pGameApp){
			POINT po={0};
			po.x = GET_X_LPARAM(lParam); 
			po.y = GET_Y_LPARAM(lParam);
			pGameApp->OnMouseMove(po);
		}
	}
	break;
	case WM_CLOSE:
		{
			int res = ::MessageBox(NULL, "[WM_CLOSE] �Ƿ�ȷ���˳�", "��ʾ", MB_OKCANCEL);
			if (res ==IDOK){ //��� ��ȷ������ť
			
			}else if (res ==IDCANCEL){//�����ȡ������ť��������Ĭ�ϵ���Ϣ���� DefWindowProc 
			
				return 0;
			}else{
				return 0;
			}
		}
		break;
	case WM_DESTROY: 
		{
			//::MessageBox(NULL, "WM_DESTROY", "��ʾ", MB_OK);
			//�ͷ���Ϸ��Դ

			if(pGameApp){
				delete pGameApp;
				pGameApp = NULL;
			}
			PostQuitMessage(0);
		}
		break;
	case WM_QUIT:
		{
			::MessageBox(NULL, "WM_QUIT", "��ʾ", MB_OK);
		}
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
	
}