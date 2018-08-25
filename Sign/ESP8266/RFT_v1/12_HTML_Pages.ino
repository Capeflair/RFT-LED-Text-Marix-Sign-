

String HTML_Generate_WifiSetup_Page(){
  String page = "<!DOCTYPE html><html><head><link rel='icon' type='image/png' href='data:image/png;base64,iVBORw0KGgo='><title>Radio Free Tankwa</title><meta charset='UTF-8'><link href='/style.css' rel='stylesheet' /></head><body><div class='a'>";
  page += "<a href='/'><h1 class='fr'>Menu</h1></a>";
  page += "<h1>Wifi Setup</h1>";
  page += "<form action='/update.php' method='post'>SSID:<br>";
  page += "<input type='hidden' name='reff' value='/wifi'/>";
  page += "<input type='text' name='ssid' value='";
  page += WiFi.SSID();
  page += "'>";
  page += "<br><br>Password:<br>";
  page += "<input type='text' name='psw'>";
  page += "<br><br><input type='submit' value='Submit'></form></div></body></html>";
  return page;
}

String HTML_Generate_Menu_Page(){
  String page = "<!DOCTYPE html><html><head><link rel='icon' type='image/png' href='data:image/png;base64,iVBORw0KGgo='><title>Radio Free Tankwa</title><meta charset='UTF-8'><link href='/style.css' rel='stylesheet' /></head><body><div class='b'>";
  page += "<h1>Menu</h1><a href='/wifi'><div class='button'>Wifi Setup</div></a><a href='http://capeflair.com/rft_sign'><div class='button'>Internet Redirect</div></a><a href='/online'><div class='button' style='background:#3C5;'>Sign Setup</div></a><a href='/internal'><div class='button'>JSON (dev)</div></a><a href='/brightness'><div class='button'>Brightness</div></a>";
  page += "<script> var d = new Date(); var http = new XMLHttpRequest(); var url = '/update.php'; var params = 'hour='+d.getHours()+'&minute='+d.getMinutes(); http.open('POST', url, true); http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded'); http.send(params);  </script>";
  page += "</div></body></html>";
  return page;
}


String HTML_Generate_Internal_Page(){
  String page = "<!DOCTYPE html><html><head><link rel='icon' type='image/png' href='data:image/png;base64,iVBORw0KGgo='><title>Radio Free Tankwa</title><meta charset='UTF-8'><link href='/style.css' rel='stylesheet' /></head><body><div class='b'>";
  page += "<a href='/'><h1 class='fr'>Menu</h1></a><h1>JSON</h1>";
  page += "<form action='/update.php' method='post'><input type='hidden' name='reff' value='/internal'/><textarea name='json_to_upload' id='JU'></textarea><input type='submit' value='Submit' /></form></div>";
  page += "<script>function loadJSON(){var myArr=JSON.parse(this.responseText);document.getElementById('JU').value=JSON.stringify(myArr);}var r = new XMLHttpRequest();r.onload = loadJSON;r.open('get', '/list', true);r.send();</script>";
  page += "<script> var d = new Date(); var http = new XMLHttpRequest(); var url = '/update.php'; var params = 'hour='+d.getHours()+'&minute='+d.getMinutes(); http.open('POST', url, true); http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded'); http.send(params);  </script>";
  page += "</div></body></html>";
  return page;
}

// Still to do

String HTML_Generate_Online_Page(){
  String page = "<!DOCTYPE html><html><head><link rel='icon' type='image/png' href='data:image/png;base64,iVBORw0KGgo='><title>Radio Free Tankwa</title><meta charset='UTF-8'><link href='/style.css' rel='stylesheet' />";
  page += "<link href='http://capeflair.com/rft_sign/rft.css' rel='stylesheet' />";
  page += "<script src='http://capeflair.com/rft_sign/java/jquery-1.8.2.min.js'></script>";
  page += "<script src='http://capeflair.com/rft_sign/java/rft.js'></script>";
  page += "</head><body><div class='b'>";
  page += "<a href='/'><h1 class='fr'>Menu</h1></a><h1>Sign Setup</h1>";
  page += "<div id='CONTROLAREA'></div>";
  page += "<form action='/update.php' method='post'><input type='hidden' name='reff' value='/online'/><textarea name='json_to_upload' style='display:none;' id='JU'></textarea><input type='submit' value='Submit' /></form></div>";  
  page += "<script> var d = new Date(); var http = new XMLHttpRequest(); var url = '/update.php'; var params = 'hour='+d.getHours()+'&minute='+d.getMinutes(); http.open('POST', url, true); http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded'); http.send(params);  </script>";
  page += "</div></body></html>";
  return page;
}

String HTML_Generate_Brightness_Page(){
  String page = "<!DOCTYPE html><html><head><link rel='icon' type='image/png' href='data:image/png;base64,iVBORw0KGgo='><title>Radio Free Tankwa</title><meta charset='UTF-8'><link href='/style.css' rel='stylesheet' /></head><body><div class='b'>";
  page += "<a href='/'><h1 class='fr'>Menu</h1></a><h1>Sign Brightness (max 255)</h1>";
  page += "<form action='/update.php' method='post'>Brightness Level:<br>";
  page += "<input type='hidden' name='reff' value='";
  page += server.uri();
  page += "'/>";
  page += "<input type='range' min='0' max='255' name='brightlevel' value='";
  page += strip.getBrightness();
  page += "'>";
  page += "<br><br><input type='submit' value='Submit'></form>";
  page += "<script> var d = new Date(); var http = new XMLHttpRequest(); var url = '/update.php'; var params = 'hour='+d.getHours()+'&minute='+d.getMinutes(); http.open('POST', url, true); http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded'); http.send(params);  </script>";
  page += "</div></body></html>";
  return page;
}


String HTML_Generate_Redirect_Page(String backurl){
  String page = "<!DOCTYPE html><html><head><link rel='icon' type='image/png' href='data:image/png;base64,iVBORw0KGgo='><title>Radio Free Tankwa</title>";
  page += "<meta http-equiv='refresh' content='0;URL=\"";
  page += backurl;
  page += "\"' />";
  page += "</head><body></body></html>";
  return page;
}


