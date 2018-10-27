#include <windows.h>
#include <locale.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>

#define NELEM(a) (sizeof(a) / sizeof(a[0]))

static
int CALLBACK EnumFontFamExProc(ENUMLOGFONTEX *lpelfe, NEWTEXTMETRICEX *lpntme, DWORD dwFontType, LPARAM lParam)
{
	_tprintf(_T("FaceName: %s, len: %u (< %u)\n"), lpelfe->elfLogFont.lfFaceName, _tcslen(lpelfe->elfLogFont.lfFaceName), NELEM(lpelfe->elfLogFont.lfFaceName));
	_tprintf(_T("FullName: %s, len: %u (< %u)\n"), lpelfe->elfFullName, _tcslen(lpelfe->elfFullName), NELEM(lpelfe->elfFullName));
	_tprintf(_T("Style   : %s, len: %u (< %u)\n"), lpelfe->elfStyle, _tcslen(lpelfe->elfStyle), NELEM(lpelfe->elfStyle));
	_tprintf(_T("Script  : %s, len: %u (< %u)\n"), lpelfe->elfScript, _tcslen(lpelfe->elfScript), NELEM(lpelfe->elfScript));
	_putts(_T("----------"));

	return 1;
}

int _tmain(int argc, _TCHAR *argv[])
{
	_tsetlocale(LC_ALL, _T("Japanese_Japan.932"));

	HWND hWnd = GetDesktopWindow();
	HDC hdc = GetDC(hWnd);
	LOGFONT lf = {0};

	lf.lfFaceName[0] = '\0';
	lf.lfCharSet = DEFAULT_CHARSET;

	EnumFontFamiliesEx(hdc, &lf, EnumFontFamExProc, 0, 0);

	return 0;
}
