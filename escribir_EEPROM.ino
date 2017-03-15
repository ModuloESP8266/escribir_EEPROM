#include <EEPROM.h>

char ssid[20];
char pass[20];
char Topic1[20];
char Topic2[20];
char ServerWan[40];
char ServerLan[20];

String ssid_leido;
String pass_leido;
String Topic1_leido;
String Topic2_leido;
String ServerWan_leido;
String ServerLan_leido;

String scanWifi;

int ssid_tamano = 0;
int pass_tamano = 0;
int Topic1_tamano = 0;
int Topic2_tamano = 0;
int ServerWan_tamano = 0;
int ServerLan_tamano = 0;

////// ADDRESS EEPROM
int dir_modo= 0; // 0=normal 1 configuracion
int dir_conf = 70;
int dir_ssid = 1;
int dir_pass = 30;
int dir_topic1 = 100;
int dir_topic2 = 130;
int dir_serverwan = 150;
int dir_serverlan = 180;
int dir_puerto = 210;

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

  EEPROM.begin(256);
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
  graba(dir_ssid,"Consola");
  graba(dir_pass,"tyrrenal");
  graba(dir_conf,"configurado");
  graba(dir_topic1,"prueba/light1");
  graba(dir_topic2,"prueba/light2");
  graba(dir_serverwan,"giovanazzi.ddns.net");
  graba(dir_serverlan,"192.168.1.106");
  graba(dir_puerto,"1883");
/*
  graba(dir_modo,"0");
  graba(dir_ssid,"");
  graba(dir_pass,"");
  graba(dir_conf,"");
  graba(dir_topic1,"");
  graba(dir_topic2,"");
  graba(dir_serverwan,"");
  graba(dir_serverlan,"");
  graba(dir_puerto,"");
   */
 
  Serial.println(lee(0)); 
  Serial.println(lee(1));
  Serial.println(lee(30));
  Serial.println(lee(70));
  Serial.println(lee(100));
  Serial.println(lee(130));
  Serial.println(lee(150));
  Serial.println(lee(180));
  Serial.println(lee(210));

  
  
  }
