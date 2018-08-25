String Generate_List_of_Strings(){
  String scroll_txt;
  String returnStr = "[";
  for (int i = 0; i < MAX_SCROLL_ITEMS; i++) {
    if (i>0) { returnStr += ","; }
    returnStr += "{";
    returnStr += "\"scroll_txt\":\"";
    scroll_txt = scroll_items[i].scroll_txt;
    scroll_txt.replace("\"","\\\"");
    returnStr += scroll_txt;
    returnStr += "\",\"animation\":\"";
    returnStr += scroll_items[i].animation;
    returnStr += "\",\"delay\":\"";
    returnStr += scroll_items[i].delay;
    returnStr += "\",\"red\":\"";
    returnStr += scroll_items[i].red;    
    returnStr += "\",\"green\":\"";
    returnStr += scroll_items[i].green;    
    returnStr += "\",\"blue\":\"";
    returnStr += scroll_items[i].blue;    
    returnStr += "\",\"cycles\":\"";
    returnStr += scroll_items[i].cycles;
    returnStr += "\"";
    returnStr += "}";
  }
  returnStr += "]";  
  return returnStr;
}


