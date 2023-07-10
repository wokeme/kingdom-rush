#include "viewmodel.h"

viewmodel::viewmodel()
{

}
void viewmodel::on_click_tower(int x,int y)
{
    std::cout<<"on_click_tower\n";
    Tower temp;
    temp.SetCoord(std::make_pair(x,y));
    temp.SetPath(":/pics/4.png");
    emit build_tower(x,y);
}
