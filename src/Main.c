#if defined __linux__
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Random.h"
#elif defined _WINE
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Random.h"
#elif defined _WIN32
#include "F:/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Random.h"
#elif defined(__APPLE__)
#error "Apple not supported!"
#else
#error "Platform not supported!"
#endif


Vector sprites;

void Setup(AlxWindow* w){
	sprites = Vector_New(sizeof(Sprite));
	Vector_PushCount(&sprites,(Sprite[]){
		Sprite_Load("./assets/NONE.png"),
		Sprite_Load("./assets/U.png"),
		Sprite_Load("./assets/D.png"),
		Sprite_Load("./assets/L.png"),
		Sprite_Load("./assets/R.png"),
		Sprite_Load("./assets/UD.png"),
		Sprite_Load("./assets/LR.png"),
		Sprite_Load("./assets/LU.png"),
		Sprite_Load("./assets/LD.png"),
		Sprite_Load("./assets/RU.png"),
		Sprite_Load("./assets/RD.png"),
		Sprite_Load("./assets/LUR.png"),
		Sprite_Load("./assets/LDR.png"),
		Sprite_Load("./assets/ULD.png"),
		Sprite_Load("./assets/URD.png"),
		Sprite_Load("./assets/UDLR.png")
	},16);
}
void Update(AlxWindow* w){
	//const Vec2 size = TransformedView_WorldScreenLength(&tv,(Vec2){ 1.0f,1.0f });
	//for(int i = 0;i<sprites.size;i++){
	//	Sprite* sp = (Sprite*)Vector_Get(&sprites,i);
	//	Sprite_Reload(sp,size.x + 1,size.y + 1);
	//}

	Clear(BLACK);

	
}
void Delete(AlxWindow* w){
	for(int i = 0;i<sprites.size;i++){
		Sprite* sp = (Sprite*)Vector_Get(&sprites,i);
		Sprite_Free(sp);		
	}
	Vector_Free(&sprites);
}

int main(){
    if(Create("Explorer",2500,1200,1,1,Setup,Update,Delete))
        Start();
    return 0;
}