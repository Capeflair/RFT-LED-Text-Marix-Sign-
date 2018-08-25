void Setup_Wifi(){
  server.on("/update.php", Wifi_Handler_Updater);
  server.on("/wifi", Wifi_Handler_SetupHTML);
  server.on("/internal", Wifi_Handler_InternalHTML);
  server.on("/list", Wifi_Handler_ListStrings);
  server.on("/style.css", Wifi_Handler_Style);
  server.on("/brightness", Wifi_Handler_BrightnessHTML);

  // still to do
  server.on("/online", Wifi_Handler_OnlineHTML);

  server.on("/", Wifi_Handler_RootPath);

  server.begin();
  Serial.println("Wifi Setup Complete");
}

void Wifi_Handler_RootPath(){
  Serial.println("-> Sending /");
  server.send(200, "text/html", HTML_Generate_Menu_Page());
}


void Wifi_Handler_Updater(){
  if (server.hasArg("ssid")){
    String _ssid = server.arg("ssid");
    _ssid.trim();
    Serial.print("New SSID: ");
    Serial.println(_ssid);    
    if (_ssid.length()>0){
      if (server.hasArg("psw")){
        String _pswd = server.arg("psw");
        _pswd.trim();
        Serial.print("New Wifi Password: ");
        Serial.println(_pswd);    
        Connect_to_wifi(_ssid.c_str(),_pswd.c_str());
      } else {
        Connect_to_wifi(_ssid.c_str(),"");
      }
    }
  }
  if (server.hasArg("json_to_upload")){
    String _json = server.arg("json_to_upload");
    _json.trim();
    Serial.print("New JSON: ");
    Serial.println(_json);    
    if (_json.length()>0){
      // sort out the new _json 
      Load_New_Strings_From_JSON(_json);
    }
  }
  if (server.hasArg("brightlevel")){
    String _brightlevel = server.arg("brightlevel");
    _brightlevel.trim();
    Serial.print("New Brightlevel: ");
    Serial.println(_brightlevel);    
    if (_brightlevel.length()>0){
      int newBright = _brightlevel.toInt();
      Change_Brightness(newBright);
    }
  }

  if (server.hasArg("hour")){
    String _hour = server.arg("hour");
    _hour.trim();
    Serial.print("New Hour: ");
    Serial.println(_hour);    
    if (_hour.length()>0){
      int newHour = _hour.toInt();
      String _minute = server.arg("minute");
      _minute.trim();
      Serial.print("New Minute: ");
      Serial.println(_minute);    
      if (_minute.length()>0){
        int newMinute = _minute.toInt();
        setTime(newHour, newMinute, 00, 14, 12, 2015);
        timeIsSet = true;
      }
    }
  }
  
  if (server.hasArg("reff")){
    Serial.print("-> Redirect to ");
    Serial.println(server.arg("reff"));
    server.send(200, "text/html", HTML_Generate_Redirect_Page(server.arg("reff")));
  }
}






void Wifi_Handler_SetupHTML(){
  Serial.println("-> Sending /wifi");
  server.send(200, "text/html", HTML_Generate_WifiSetup_Page());
}


void Wifi_Handler_InternalHTML(){
  Serial.println("-> Sending /internal");
  server.send(200, "text/html", HTML_Generate_Internal_Page());
}

void Wifi_Handler_OnlineHTML(){
  Serial.println("-> Sending /online");
  server.send(200, "text/html", HTML_Generate_Online_Page());
}

void Wifi_Handler_BrightnessHTML(){
  Serial.println("-> Sending /brightness");
  server.send(200, "text/html", HTML_Generate_Brightness_Page());
}

void Wifi_Handler_Style(){
  Serial.println("-> Sending /style.css");
  server.send(200, "text/css", HTML_GenerateCSS());
}


void Wifi_Handler_ListStrings(){
  Serial.println("-> Sending /list");
  server.send(200, "application/json", Generate_List_of_Strings());
}










void Connect_to_last_wifi() {
  if (WiFi.SSID()) {
    wifi_operation_delay = WIFI_START_UP_TIME;
    Serial.print("Connecting to old wifi connection : ");
    Serial.println(WiFi.SSID());
    WiFi.begin();
    wifi_waiting_for_old_connection = true;
  } else {
    wifi_default_connection_LIVE = true;
    Connect_to_wifi(def_ssid, def_password);    
  }
}

void WiFi_Check_Old_Connection(){
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Old connection failed");
    wifi_waiting_for_old_connection = false;  
    Connect_to_wifi(def_ssid, def_password);
    wifi_default_connection_LIVE = true;
  } else {
    Serial.println(" Reconnected to old WIFI!");
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
    WiFi_Post_To_CF("local_ip",IpAddress2String(WiFi.localIP()));
    WiFi_Post_To_CF("ssid",WiFi.SSID());
    wifi_waiting_for_old_connection = false;  
    wifi_operation_delay = 0;
  }
}


void Connect_to_wifi(const char* ssid, const char* pw) {
//  WiFi_Scan_Networks();
//  Serial.print("MAC ADDRESS : ");
//  Serial.println(WiFi.macAddress());
  wifi_operation_delay = 50;
  wifi_lost_connection_count=0;
  WiFi.begin(ssid, pw);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  wifi_waiting_for_connection = true;
}


void WiFi_Lost_Connection_Check(){
  wifi_lost_connection_count++;
  wifi_operation_delay = 50;
  // IF WE'VE LOST CONNECTION FOR +-60sec THEN TRY OTHER DEFAULT
  if (wifi_lost_connection_count>1200) {
    wifi_lost_connection_count = 0;
    if (wifi_default_connection_LIVE) {
      wifi_waiting_for_old_connection = false;  
      Connect_to_wifi(def_ssid, def_password);
      wifi_default_connection_LIVE = false;
    } else {
      wifi_waiting_for_old_connection = false;  
      Connect_to_wifi(def_ssid_1, def_password_1);
      wifi_default_connection_LIVE = true;
    }
  }
}

bool WiFi_Check_Connection() {
  if (WiFi.status() != WL_CONNECTED) {
    wifi_lost_connection_count++;
    if (wifi_lost_connection_count%30==0){
      Serial.print(".");
//      Serial.print("IP address: ");
//      Serial.println(WiFi.localIP());
    }
    wifi_operation_delay = 50;
    // IF NO CONNECTION AFTER +-60sec THEN TRY OTHER DEFAULT
    if (wifi_lost_connection_count>1200) {
      wifi_lost_connection_count = 0;
      if (wifi_default_connection_LIVE) {
        wifi_waiting_for_old_connection = false;  
        Connect_to_wifi(def_ssid, def_password);
        wifi_default_connection_LIVE = false;
      } else {
        wifi_waiting_for_old_connection = false;  
        Connect_to_wifi(def_ssid_1, def_password_1);
        wifi_default_connection_LIVE = true;
      }
    }
  
  } else {
    Serial.println(" WIFI Connected!");
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
    WiFi_Post_To_CF("local_ip",IpAddress2String(WiFi.localIP()));
    WiFi_Post_To_CF("ssid",WiFi.SSID());
    wifi_waiting_for_connection = false;  
    wifi_lost_connection_count = 0;
    wifi_operation_delay = 0;
  }
}

String IpAddress2String(const IPAddress& ipAddress) {
  return String(ipAddress[0]) + String(".") + String(ipAddress[1]) + String(".") + String(ipAddress[2]) + String(".") + String(ipAddress[3])  ; 
}

void WiFi_Post_To_CF(String key, String val){
  String topost = "key="+key+"&value="+val;

  HTTPClient http;
  http.begin("http://capeflair.com/rft_sign/update.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.POST(topost);
  http.writeToStream(&Serial);
  http.end();  

}

void WiFi_Scan_Networks(){
  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");
}

