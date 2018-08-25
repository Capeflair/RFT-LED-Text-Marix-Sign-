

void run_timer() {
    int i;
    long current_millis;

    // get current time
    current_millis = millis();
    
    run_sign_timer(current_millis);
    run_wifi_timer(current_millis);
}

void run_sign_timer(long current_millis){
    if (show_scroll_item>=0) {
      if (current_millis - scroll_items[show_scroll_item].prev_millis >= scroll_items[show_scroll_item].delay) {
        scroll_items[show_scroll_item].prev_millis = current_millis;
        Run_Sign_String();
      }
    }
}


void run_wifi_timer(long current_millis){
  if (current_millis - wifi_prev_millis >= wifi_operation_delay) {
    wifi_prev_millis = current_millis;    
    if (wifi_waiting_for_old_connection) {
      WiFi_Check_Old_Connection();
    } else if (wifi_waiting_for_connection) {
      WiFi_Check_Connection();
    } else {
      if (WiFi.status() != WL_CONNECTED) {
        WiFi_Lost_Connection_Check();
      } else {
        wifi_lost_connection_count = 0;
        wifi_operation_delay = 0;
        server.handleClient();
      }
    }
  }
}
