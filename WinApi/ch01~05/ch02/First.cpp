#include<Windows.h>


/*
VS ERROR LNK2019 : _main 외부 기호(참조 위치: "int __cdecl invoke_main(void)" (?invoke_main@@YAHXZ) 함수)에서 확인하지 못했습니다.
*/
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst; // g_hInst 는 전체적으로 자주 사용되기에 전역변수 선언 
LPCTSTR lpszClass = TEXT("CH02");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;  // 윈도우 컨트롤을 위한 핸들 
	MSG Message; // 윈도우 메시지 처리를 위한 구조체 
	WNDCLASS WndClass; // Window Class 생성  
	g_hInst = hInstance;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	WndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance = hInstance; // 프로그램 구분자 
	WndClass.lpfnWndProc = WndProc;  // 메시지처리를 위한 Wndproce 등록 
	WndClass.lpszClassName = lpszClass; // 해당 윈도우 이름 
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);
	hWnd = CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow); // 사용자에게 윈도우 화면 보여주기 
	while (GetMessage(&Message,NULL,0,0))  // 메시지 큐에서 메시지가지고 오기 - WM_QUIT 메시지를 받으면 종료 
	{
		TranslateMessage(&Message);  // 프로그램 내에서 쉽게 메시지 처리를 위해 변환   
		DispatchMessageW(&Message);  // 꺼내온 메시지를 Winproc로 전달 
	}
	return (int)Message.wParam; 
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // 윈도우에서 발생된 메시지 처리를 위한 콜백함수 
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