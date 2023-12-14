#include <windows.h>

bool running = true; 

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LRESULT result = 0; 

	switch (uMsg){
		case WM_CLOSE:
		case WM_DESTROY: {
			running = false;
		} break; 
		default: {
			result = DefWindowProc(hwnd, uMsg, wParam, lParam);
		}

	}
	return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	//Creation window class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = "Game Window Class";
	window_class.lpfnWndProc = window_callback;
	//Register class
	RegisterClass(&window_class);
	
	//Create window
	HWND window = CreateWindowA(window_class.lpszClassName, "mon premier jeu", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);

	while (running){
		//input
		MSG message; 
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessageA(&message);
			
		}

		//simulate

		//render

	}
}