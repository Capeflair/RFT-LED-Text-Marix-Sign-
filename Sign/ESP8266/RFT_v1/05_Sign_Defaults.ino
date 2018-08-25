
void Load_Default_Sign_Strings(){
  long current_millis = millis();  
  int i=0;
  

  scroll_items[i].scroll_txt = "";
  scroll_items[i].animation = "ColorWipe_Rainbow";
  scroll_items[i].delay = 10;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].cycles = 1;
  i++;

  scroll_items[i].scroll_txt = "";
  scroll_items[i].animation = "RainbowCycle_MovingLeft";
  scroll_items[i].delay = 10;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].cycles = 2;
  i++;

  scroll_items[i].scroll_txt = "";
  scroll_items[i].animation = "ColorWipe";
  scroll_items[i].delay = 5;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].cycles = 1;
  i++;

  scroll_items[i].scroll_txt = "Radio Free Tankwa 99.9FM";
  scroll_items[i].animation = "RainbowString2";
  scroll_items[i].delay = 110;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].red =100;
  scroll_items[i].green =255;
  scroll_items[i].blue =100;
  i++;
  

  scroll_items[i].scroll_txt = "Arrr";
  scroll_items[i].animation = "RainbowString2";
  scroll_items[i].delay = 50;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].red =255;
  scroll_items[i].green =255;
  scroll_items[i].blue =0;
  i++;


  scroll_items[i].scroll_txt = "and the time is...";
  scroll_items[i].animation = "String";
  scroll_items[i].delay = 50;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].red =255;
  scroll_items[i].green =255;
  scroll_items[i].blue =0;
  i++;

  scroll_items[i].scroll_txt = "";
  scroll_items[i].animation = "ShowTimeIsh";
  scroll_items[i].delay = 2500;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].red =255;
  scroll_items[i].green =255;
  scroll_items[i].blue =0;
  i++;


  scroll_items[i].scroll_txt = "ICE opens at 11ish";
  scroll_items[i].animation = "String";
  scroll_items[i].delay = 100;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].red = 255;
  scroll_items[i].green =40;
  scroll_items[i].blue =0;
  scroll_items[i].cycles = 1;
  i++;
  

  scroll_items[i].scroll_txt = "";
  scroll_items[i].animation = "ColorWipe";
  scroll_items[i].delay = 20;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].red = 18;
  scroll_items[i].green =236;
  scroll_items[i].blue =255;
  scroll_items[i].cycles = 1;
  i++;

  scroll_items[i].scroll_txt = "";
  scroll_items[i].animation = "ColorWipe";
  scroll_items[i].delay = 20;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].red = 0;
  scroll_items[i].green =0;
  scroll_items[i].blue =0;
  scroll_items[i].cycles = 1;
  i++;


  scroll_items[i].scroll_txt = "Don't be a darktard";
  scroll_items[i].animation = "String";
  scroll_items[i].delay = 60;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].red = 141;
  scroll_items[i].green =249;
  scroll_items[i].blue =0;
  scroll_items[i].cycles = 1;
  i++;

  scroll_items[i].scroll_txt = "Be Awesome";
  scroll_items[i].animation = "String";
  scroll_items[i].delay = 50;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].red = 121;
  scroll_items[i].green =128;
  scroll_items[i].blue =255;
  scroll_items[i].cycles = 1;
  i++;

  scroll_items[i].scroll_txt = "HuG a stranGer";
  scroll_items[i].animation = "RainbowString";
  scroll_items[i].delay = 50;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].cycles = 1;
  i++;

  scroll_items[i].scroll_txt = "TUNE";
  scroll_items[i].animation = "StaticString";
  scroll_items[i].delay = 600;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].red = 140;
  scroll_items[i].green =0;
  scroll_items[i].blue =255;
  scroll_items[i].cycles = 1;
  i++;

  scroll_items[i].scroll_txt = "Weather Tomorrow: Breezy";
  scroll_items[i].animation = "RainbowString";
  scroll_items[i].delay = 60;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].cycles = 1;
  i++;

  scroll_items[i].scroll_txt = "NW Wind / Max 20 / Min 13";
  scroll_items[i].animation = "RainbowString2";
  scroll_items[i].delay = 60;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].cycles = 1;
  i++;


  scroll_items[i].scroll_txt = "DUST";
  scroll_items[i].animation = "ScrollUpString";
  scroll_items[i].delay = 5;
  scroll_items[i].prev_millis = current_millis;
  scroll_items[i].init_millis = current_millis;
  scroll_items[i].total_millis = -1;
  scroll_items[i].red = 255;
  scroll_items[i].green =40;
  scroll_items[i].blue =0;
  scroll_items[i].cycles = 1;
  i++;


  total_scroll_items = i;
}
