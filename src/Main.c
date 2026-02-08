#if defined __linux__
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Explorer.h"
#elif defined _WINE
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Explorer.h"
#elif defined _WIN32
#include "F:/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Explorer.h"
#elif defined(__APPLE__)
#error "Apple not supported!"
#else
#error "Platform not supported!"
#endif


Explorer ex;

void Setup(AlxWindow* w){
	ex = Explorer_New("..",Rect_New(
		(Vec2){ 10.0f,10.0f },
		(Vec2){ 500.0f,GetHeight() - 20 }
	));
}
void Update(AlxWindow* w){
	Explorer_Update(&ex,w->Strokes,GetMouse());

	Clear(BLACK);

	Explorer_Render(&ex,WINDOW_STD_ARGS);
}
void Delete(AlxWindow* w){
	Explorer_Free(&ex);
}

int main(){
    if(Create("Explorer",2500,1200,1,1,Setup,Update,Delete))
        Start();
    return 0;
}