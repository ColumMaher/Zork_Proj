#include "item.h"
Item::Item(QString name)
{
    this->name = name;
    if(name == "Shattered Sword"){
        this->weapon = true;
        this->damage = 10;
    }else if(name == "Spear"){
        this->weapon = true;
        this->damage = 20;
    }else if(name == "Mjolnir"){
        this->weapon = true;
        this->damage = 50;
    }else if(name == "Weak Potion"){
        this->potion = true;
        this->heal = 15;
    }else if(name == "Potion"){
        this->potion = true;
        this->heal = 30;
    }else if(name == "Strong Potion"){
        this->potion = true;
        this->heal = 50;
    }else if(name == "The Key"){
        this->key = true;
        this->room = 'C';
        this->current = 'B';
        this->direction = 'W';
    } else if(name == "Black-White Potion"){
        this->potion = true;
        this->heal = 100;
    } else if(name == "Red-Blue Potion"){
        this->potion = true;
        this->heal = -100;
    } else if(name == "Pink-Yellow Potion"){
        this->potion = true;
        this->heal = -100;
    }
}
Item::Item(const Item& item){
    this->name = item.name;
    if(name == "Shattered Sword"){
        this->weapon = true;
        this->damage = 10;
    }else if(name == "Spear"){
        this->weapon = true;
        this->damage = 20;
    }else if(name == "Mjolnir"){
        this->weapon = true;
        this->damage = 50;
    }else if(name == "Weak Potion"){
        this->potion = true;
        this->heal = 15;
    }else if(name == "Potion"){
        this->potion = true;
        this->heal = 30;
    }else if(name == "Strong Potion"){
        this->potion = true;
        this->heal = 50;
    }else if(name == "The Key"){
        this->key = true;
        this->room = 'C';
        this->current = 'B';
        this->direction = 'W';
    } else if(name == "Black-White Potion"){
        this->potion = true;
        this->heal = 100;
    } else if(name == "Red-Blue Potion"){
        this->potion = true;
        this->heal = -100;
    } else if(name == "Pink-Yellow Potion"){
        this->potion = true;
        this->heal = -100;
    }
}
Item::Item(){
}
Item::~Item(){
}
