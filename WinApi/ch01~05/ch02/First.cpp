#include<Windows.h>


/*
VS ERROR LNK2019 : _main �ܺ� ��ȣ(���� ��ġ: "int __cdecl invoke_main(void)" (?invoke_main@@YAHXZ) �Լ�)���� Ȯ������ ���߽��ϴ�.
*/
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst; // g_hInst �� ��ü������ ���� ���Ǳ⿡ �������� ���� 
LPCTSTR lpszClass = TEXT("CH02");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;  // ������ ��Ʈ���� ���� �ڵ� 
	MSG Message; // ������ �޽��� ó���� ���� ����ü 
	WNDCLASS WndClass; // Window Class ����  
	g_hInst = hInstance;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	WndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance = hInstance; // ���α׷� ������ 
	WndClass.lpfnWndProc = WndProc;  // �޽���ó���� ���� Wndproce ��� 
	WndClass.lpszClassName = lpszClass; // �ش� ������ �̸� 
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);
	hWnd = CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow); // ����ڿ��� ������ ȭ�� �����ֱ� 
	while (GetMessage(&Message,NULL,0,0))  // �޽��� ť���� �޽��������� ���� - WM_QUIT �޽����� ������ ���� 
	{
		TranslateMessage(&Message);  // ���α׷� ������ ���� �޽��� ó���� ���� ��ȯ   
		DispatchMessageW(&Message);  // ������ �޽����� Winproc�� ���� 
	}
	return (int)Message.wParam; 
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // �����쿡�� �߻��� �޽��� ó���� ���� �ݹ��Լ� 
{
	switch (iMessage)
	{
	case WM_DESTROY :
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN :
		MessageBeep(0);
		return 0;
	default:
		break;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}