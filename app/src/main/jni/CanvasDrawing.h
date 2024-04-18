#ifndef X_SKILL_CHEATS_CANVASDRAWING_H
#define X_SKILL_CHEATS_CANVASDRAWING_H
#include <chrono>
#include "socket.h"
#include "CanvasColors.h"
#include "MainLoader.h"
//#include "Login.h"

Request request;
Response response;
float x,y;
char extra[30];
int botCount,playerCount;
Color clr,clrHealth, _colorByDistance,_colorByDistance2;

Options options{1,-1,3, false,1, false,201
};
bool isInCenter(Rect box,int screenWidth,int screenHeight){
                Vec2 centerPos = Vec2(screenWidth / 2, screenHeight / 2);
                if(box.x <centerPos.x && box.y <centerPos.y){
               return true;
}
               return false;
}
uint64_t GetTickCount() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

class Interval {
private: 
    int initial_;

public:
    inline Interval() : initial_(GetTickCount()) {}

    virtual ~Interval() {}

    inline unsigned int value() const {
        return GetTickCount() - initial_;
    }
};

class FPS {
protected:
    int32_t m_fps;
    int32_t m_fpscount;
    Interval m_fpsinterval;

public:
    FPS() : m_fps(0), m_fpscount(0) {}

    void Update() {
        m_fpscount++;
        if (m_fpsinterval.value() > 1000) {
            m_fps = m_fpscount;
            m_fpscount = 0;
            m_fpsinterval = Interval();
        }
    }

    int32_t get() const {
        return m_fps;
    }
};

FPS m_fps;

void DrawESP(ESP Cdraw, int screenWidth, int screenHeight) {
   // if(isESP) {
    botCount=0;playerCount=0;
    request.ScreenHeight=screenHeight;
    request.ScreenWidth=screenWidth;
    request.Mode=InitMode;
    request.options=options;
    send((void*)&request,sizeof(request));
    receive((void*)&response);
   
    m_fps.Update();
    char *tsr = ("7H INJECTOR: ");
    std::string Str = std::string(tsr);
    Str += std::to_string((int) m_fps.get());
    if (showFPSOnScreen){
    Cdraw.DrawText(Color::Green(), Str.c_str(), Vec2(150, 50), 22);
	}		     	 
	if(options.openState== 0)
            Cdraw.DrawCircle2(Color(255,0,0),Vec2(screenWidth/2,screenHeight/2),request.options.aimingRange,screenHeight/500);	
        char hello[50]="failed";
        if(response.Success) {
            float textsize=screenHeight/50;
            for (int i = 0; i < response.PlayerCount; i++) {
                x = response.Players[i].HeadLocation.x;
                y = response.Players[i].HeadLocation.y;

                 if (response.Players[i].isBot) {
                    botCount++;

                    clr.r = 30;
                    clr.g = 232;
                    clr.b = 222;
                    clr.a = 255;
                } else {
                    playerCount++;
                    clr.r = 255;
                    clr.g = 0;
                    clr.b = 0;
                    clr.a = 255;
                }
                float magic_number = (response.Players[i].Distance * response.fov);
                float mx = (screenWidth / 4) / magic_number;
                float my = (screenWidth / 1.38) / magic_number;
                float top = y - my + (screenWidth / 1.7) / magic_number;
                float bottom = y + my + screenHeight / 4 / magic_number;
                Rect BoxRect(x - mx, top, x + mx, bottom);
                Color _colorByDistance2 = colorByDistance2((int)response.Players[i].Distance, 255);
                bool playerInCenter = isInCenter(BoxRect,screenWidth,screenHeight);
                
               Color skclr = playerInCenter ? Color::Green() : Color::Red();   


            for (int i = 0; i < response.GrenadeCount; i++){
                if(!isGrenadeWarning)
                    continue;
                Cdraw.DrawText(Color(255, 89, 200),"Warning: Grenade",Vec2(screenWidth/2,screenHeight/8),textsize);
                if(response.Grenade[i].Location.z!=1.0f){
                         if(response.Grenade[i].type==1 )
                        Cdraw.DrawText(Color(255,0,0),"Grenade",Vec2(response.Grenade[i].Location.x,response.Grenade[i].Location.y),textsize);
                    else
                        Cdraw.DrawText(Color(255, 158, 89),"Molotov",Vec2(response.Grenade[i].Location.x,response.Grenade[i].Location.y),textsize);
                }
            }
            for(int i = 0; i < response.VehicleCount; i++){
                if(response.Vehicles[i].Location.z!=1.0f) {
                    Cdraw.DrawVehicles(response.Vehicles[i].VehicleName,response.Vehicles[i].Distance,Vec2(response.Vehicles[i].Location.x,response.Vehicles[i].Location.y),textsize);

                }
            }
           for(int i = 0; i < response.ItemsCount; i++){
               if(response.Items[i].Location.z!=1.0f) {
                   Cdraw.DrawItems(response.Items[i].ItemName,response.Items[i].Distance,Vec2(response.Items[i].Location.x,response.Items[i].Location.y),textsize);
               }
           }

                if (response.Players[i].HeadLocation.z != 1) {

                    if (x > -50 && x < screenWidth + 50) {//onScreen

                        if (isSkelton && response.Players[i].Bone.isBone) {  //Skelton
                            Cdraw.DrawLine(skclr, 1.5, Vec2(x, y),
                                         Vec2(response.Players[i].Bone.neck.x,
                                              response.Players[i].Bone.neck.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.neck.x,
                                                                  response.Players[i].Bone.neck.y),
                                         Vec2(response.Players[i].Bone.cheast.x,
                                              response.Players[i].Bone.cheast.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.cheast.x,
                                                                  response.Players[i].Bone.cheast.y),
                                         Vec2(response.Players[i].Bone.pelvis.x,
                                              response.Players[i].Bone.pelvis.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.neck.x,
                                                                  response.Players[i].Bone.neck.y),
                                         Vec2(response.Players[i].Bone.lSh.x,
                                              response.Players[i].Bone.lSh.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.neck.x,
                                                                  response.Players[i].Bone.neck.y),
                                         Vec2(response.Players[i].Bone.rSh.x,
                                              response.Players[i].Bone.rSh.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.lSh.x,
                                                                  response.Players[i].Bone.lSh.y),
                                         Vec2(response.Players[i].Bone.lElb.x,
                                              response.Players[i].Bone.lElb.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.rSh.x,
                                                                  response.Players[i].Bone.rSh.y),
                                         Vec2(response.Players[i].Bone.rElb.x,
                                              response.Players[i].Bone.rElb.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.lElb.x,
                                                                  response.Players[i].Bone.lElb.y),
                                         Vec2(response.Players[i].Bone.lWr.x,
                                              response.Players[i].Bone.lWr.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.rElb.x,
                                                                  response.Players[i].Bone.rElb.y),
                                         Vec2(response.Players[i].Bone.rWr.x,
                                              response.Players[i].Bone.rWr.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.pelvis.x,
                                                                  response.Players[i].Bone.pelvis.y),
                                         Vec2(response.Players[i].Bone.lTh.x,
                                              response.Players[i].Bone.lTh.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.pelvis.x,
                                                                  response.Players[i].Bone.pelvis.y),
                                         Vec2(response.Players[i].Bone.rTh.x,
                                              response.Players[i].Bone.rTh.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.lTh.x,
                                                                  response.Players[i].Bone.lTh.y),
                                         Vec2(response.Players[i].Bone.lKn.x,
                                              response.Players[i].Bone.lKn.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.rTh.x,
                                                                  response.Players[i].Bone.rTh.y),
                                         Vec2(response.Players[i].Bone.rKn.x,
                                              response.Players[i].Bone.rKn.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.lKn.x,
                                                                  response.Players[i].Bone.lKn.y),
                                         Vec2(response.Players[i].Bone.lAn.x,
                                              response.Players[i].Bone.lAn.y));
                            Cdraw.DrawLine(skclr, 1.5, Vec2(response.Players[i].Bone.rKn.x,
                                                                  response.Players[i].Bone.rKn.y),
                                         Vec2(response.Players[i].Bone.rAn.x,
                                              response.Players[i].Bone.rAn.y));
                        }
                        if (isPlayerBox) {    
                            Color skclr = playerInCenter ? Color::Green() : Color::Red();                                           
                            Cdraw.DrawRect(skclr, screenHeight / 500, Vec2(x - mx, top),Vec2(x + mx, bottom));
                           }						 
                            if (isPlayerHealth) {
                            float healthLength = screenWidth / 25;
                            if (healthLength < mx)
                                healthLength = mx;
                            if (response.Players[i].Health < 25)
                                clrHealth = Color(255, 0, 0, 60);
                            else if (response.Players[i].Health < 60)
                                clrHealth = Color(255, 165, 0, 60);
                            else if (response.Players[i].Health < 75)
                                clrHealth = Color(255, 255, 0, 60);
                            else
                                clrHealth = Color(0, 255, 0, 60);
                            if (response.Players[i].Health == 0)
                                Cdraw.DrawText(Color(255, 0, 0),"Knocked",
                                             Vec2(x, top - screenHeight / 225), textsize);
                            else {
                                Cdraw.DrawFilledRect(clrHealth,
                                                   Vec2(x - healthLength, top - screenHeight / 28),
                                                   Vec2(x - healthLength + (2 * healthLength) * response.Players[i].Health /100, top - screenHeight / 75));
                                Cdraw.DrawRect(Color(0, 0, 0), screenHeight / 660,
                                             Vec2(x - healthLength, top - screenHeight / 28),
                                             Vec2(x + healthLength, top - screenHeight / 75));
                            }
                        }
                        if (isPlayerHead)
                           Color skclr = playerInCenter ? Color::Green() : Color::Red();   
                            Cdraw.DrawFilledCircle(skclr,Vec2(response.Players[i].HeadLocation.x,
                                                      response.Players[i].HeadLocation.y),
                                                 screenHeight / 12 / magic_number);
                     if (isPlayerName)
                        if (response.Players[i].isBot) {
                            Cdraw.DrawNameBot(Color().White(), response.Players[i].PlayerNameByte,
                                            response.Players[i].TeamID,
                                            Vec2(x - -2, top - 6), textsize);
                        } else {                           
                               Cdraw.DrawName(Color().White(), response.Players[i].PlayerNameByte,
                                         response.Players[i].TeamID,
                                         Vec2(x, top - screenHeight / 60), textsize);
                      };
                        if (isPlayerDist) {
                            sprintf(extra, "%0.0f m", response.Players[i].Distance);
                            Cdraw.DrawText(Color::Yellow(), extra,
                                         Vec2(x, bottom + screenHeight / 60),
                                         textsize);
                        }                 
                        if (isEnemyWeapon && response.Players[i].Weapon.isWeapon)
                           Cdraw.DrawWeapon(Color(247, 244, 200), response.Players[i].Weapon.id,
                                           response.Players[i].Weapon.ammo,
                                           Vec2(x, bottom + screenHeight / 27), textsize);
                    }
                }	
                			                      
               if (response.Players[i].HeadLocation.z == 1.0f) {
                    if (!isr360Alert)
                        continue;
                    if (y > screenHeight - screenHeight / 12)
                        y = screenHeight - screenHeight / 12;
                    else if (y < screenHeight / 12)
                        y = screenHeight / 12;
                    if (x < screenWidth / 2) {
                        Cdraw.DrawFilledCircle(_colorByDistance, Vec2(screenWidth, y),
                                             screenHeight / 18);
                        sprintf(extra, "%0.0f M", response.Players[i].Distance);

                        Cdraw.DrawText(Color(180, 250, 181, 200), extra,
                                     Vec2(screenWidth - screenWidth / 80, y), textsize);

                    } else {
                        Cdraw.DrawFilledCircle(_colorByDistance, Vec2(0, y),
                                             screenHeight / 18);
                        sprintf(extra, "%0.0f M", response.Players[i].Distance);
                        Cdraw.DrawText(Color(180, 250, 181, 200), extra,
                                     Vec2(screenWidth / 80, y), textsize);
                    }
                } else if (x < -screenWidth / 10 || x > screenWidth + screenWidth / 10) {
                    if (!isr360Alert)
                        continue;
                    if (y > screenHeight - screenHeight / 12)
                        y = screenHeight - screenHeight / 12;
                    else if (y < screenHeight / 12)
                        y = screenHeight / 12;
                    if (x > screenWidth / 2) {
                        Cdraw.DrawFilledCircle(_colorByDistance, Vec2(screenWidth, y),
                                             screenHeight / 18);
                        sprintf(extra, "%0.0f M", response.Players[i].Distance);

                        Cdraw.DrawText(Color(180, 250, 181, 200), extra,
                                     Vec2(screenWidth - screenWidth / 80, y), textsize);

                    } else {
                        Cdraw.DrawFilledCircle(_colorByDistance, Vec2(0, y),
                                             screenHeight / 18);
                        sprintf(extra, "%0.0f M", response.Players[i].Distance);
                        Cdraw.DrawText(Color(180, 250, 181, 200), extra,
                                     Vec2(screenWidth / 80, y), textsize);
                    }
                }
                    //darw line
                else if (isPlayerLine)
                    Cdraw.DrawLine(_colorByDistance2, screenHeight / 500,

                                 Vec2(screenWidth / 2, screenHeight / 12), Vec2(x, top - 80 + 80));
                //Vec2(screenWidth / 2, 80),
            }
                                         	 	
        }				
			int colors;            
            if (playerCount + botCount != 0){
                colors = 2;
                if (playerCount + botCount > 5)
                    colors = 2;
                if (playerCount + botCount > 10)
                    colors = 3;
                if (playerCount + botCount > 15)
                    colors = 4;
                sprintf(extra, "%d", playerCount + botCount);
            } else {
                colors = 1;
                strcpy(extra, "CLEAR");
            }
            Cdraw.DrawEnemyCount(colors, Vec2(Cdraw.getWidth()/2, 1));
            Cdraw.DrawText2(Color::Black(), extra, Vec2(Cdraw.getWidth() / 2, 89), 20);
        		   
			}

#endif //X_SKILL_CHEATS_CANVASDRAWING_H
//Made By @VinayakYT1  
