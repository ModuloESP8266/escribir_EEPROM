#include <EEPROM.h>

char ssid[20];
char pass[20];
char Topic1[30];
char Topic2[30];
char TopicSensor[30];
char TopicPir[30];
char ServerWan[30];
char ServerLan[30];
char Home[20];
char Floor[20];
char Site[20];
char Id[20];
char Department[20];
char Port[5];
char UserMqtt[20];
char PassMqtt[20];

String ssid_leido;
String pass_leido;
String Home_leido;
String Floor_leido;
String Site_leido;
String Id_leido;
String Department_leido;
String Topic1_leido;
String Topic2_leido;
String TopicSensor_leido;
String TopicPir_leido;
String ServerWan_leido;
String ServerLan_leido;
String Port_leido;
String UserMqtt_leido;
String PassMqtt_leido;

String scanWifi;

int ssid_tamano = 0;
int pass_tamano = 0;
int Home_tamano;
int Floor_tamano;
int Site_tamano;
int Id_tamano;
int Department_tamano;
int Topic1_tamano = 0;
int Topic2_tamano = 0;
int TopicSensor_tamano = 0;
int TopicPir_tamano = 0;
int ServerWan_tamano = 0;
int ServerLan_tamano = 0;
int Port_tamano = 0;
int UserMqtt_tamano = 0;
int PassMqtt_tamano = 0;

////// ADDRESS EEPROM
int dir_modo= 0; //0=normal 1 configuracion
int dir_ssid = 1;
int dir_pass = 30;
int dir_conf = 70;
int dir_topic1 = 100;
int dir_topic2 = 130;
int dir_serverwan = 160;
int dir_serverlan = 190;
int dir_puerto = 220;
int dir_topic_sensor = 230;
int dir_topic_pir = 260;
int dir_department= 280;
int dir_home =300;
int dir_floor =320;
int dir_site =340;
int dir_id=360;
int dir_userMqtt=380;
int dir_passMqtt=400;

String arregla_simbolos(String a) {
  a.replace("%C3%A1", "Ã¡");
  a.replace("%C3%A9", "Ã©");
  a.replace("%C3%A", "i");
  a.replace("%C3%B3", "Ã³");
  a.replace("%C3%BA", "Ãº");
  a.replace("%21", "!");
  a.replace("%23", "#");
  a.replace("%24", "$");
  a.replace("%25", "%");
  a.replace("%26", "&");
  a.replace("%27", "/");
  a.replace("%28", "(");
  a.replace("%29", ")");
  a.replace("%3D", "=");
  a.replace("%3F", "?");
  a.replace("%27", "'");
  a.replace("%C2%BF", "Â¿");
  a.replace("%C2%A1", "Â¡");
  a.replace("%C3%B1", "Ã±");
  a.replace("%C3%91", "Ã‘");
  a.replace("+", " ");
  a.replace("%2B", "+");
  a.replace("%22", "\"");
  return a;
}

void setup() {
  
  Serial.begin(115200);
  Serial.println();

  EEPROM.begin(512);
  delay(10);
  WriteDataEprom(); 

}

void loop() {
  // put your main code here, to run repeatedly:

}
  
//*******  G R A B A R  EN LA  E E P R O M  ***********
void graba(int addr, String a) {
  int tamano = (a.length() + 1);
  Serial.print(tamano);
  char inchar[30];    //'30' TamaÃ±o maximo del string
  a.toCharArray(inchar, tamano);
  EEPROM.write(addr, tamano);
  for (int i = 0; i < tamano; i++) {
    addr++;
    EEPROM.write(addr, inchar[i]);
  }
  EEPROM.commit();
}

//*******  L E E R   EN LA  E E P R O M    **************
String lee(int addr) {
  String nuevoString;
  int valor;
  int tamano = EEPROM.read(addr);
  for (int i = 0; i < tamano; i++) {
    addr++;
    valor = EEPROM.read(addr);
    nuevoString += (char)valor;
  }
  return nuevoString;
}

void WriteDataEprom(){
 
  graba(dir_modo,"0");
  graba(dir_conf,"configurado");
  
  graba(dir_ssid,"Consola");
  graba(dir_pass,"tyrrenal");
  graba(dir_serverwan,"idirect.dlinkddns.com");
  graba(dir_serverlan,"192.168.1.106");
  graba(dir_puerto,"1883");

  graba(dir_home, "casa");
  graba(dir_floor, "piso-0");
  graba(dir_department, "dto-0");
  graba(dir_site, "living");  
  
  graba(dir_id, "esp-00");
  graba(dir_topic1,"light1");
  graba(dir_topic2,"light2");
  graba(dir_topic_sensor, "dht11");
  graba(dir_topic_pir, "pir");
 
  graba(dir_userMqtt, "diego");
  graba(dir_passMqtt, "24305314");


  Serial.println("Lectura"); 
  Serial.println();
  Serial.println(lee(dir_modo)); 
  Serial.println(lee(dir_conf));
  
  Serial.println(lee(dir_ssid));
  Serial.println(lee(dir_pass));
  Serial.println(lee(dir_serverwan));
  Serial.println(lee(dir_serverlan));
  Serial.println(lee(dir_puerto));

  Serial.println(lee(dir_home));
  Serial.println(lee(dir_floor));
  Serial.println(lee(dir_department));
  Serial.println(lee(dir_site));
  
  Serial.println(lee(dir_id));
  Serial.println(lee(dir_topic1));
  Serial.println(lee(dir_topic2));
  Serial.println(lee(dir_topic_sensor));
  Serial.println(lee(dir_topic_pir));

  Serial.println(lee(dir_userMqtt));
  Serial.println(lee(dir_passMqtt));

   
  }
