/*
Programa para simular funcion dunha fiestra movil de maneira simplificada. 
O pulsador acciona o motor de subida o ser premido. Unha segunda pulsacion
fai que se accione o motor de baixada. O percorrido dura 7 segundos.Mentres 
os motores están accionados, deben responder ao accionamento do pulsador
(responsive). Ao comezo da simulacion, o motor que neste caso fai elevar a xanela, accionase automáticamente, simulando o peche da xanela.
Nos podemos interrumpir a subida premendo no boton que provoca o accionamento do seguinte motor e fai que baixe a xanela, durante 7 segundos, igual que cando sobe.

Entrada: Pulsador (dixital)            //Aquí explicamos que o arduino consta dunha entrada dixital que e o pulsador.
Saidas: Rele (2x dixital)              // Aquí explicamos que o arduino consta de dúas saídas dixitas, neste caso a dous relés.

Autor: Manuel Dominguez
Data: 2 Febreiro de 2023
*/

#define motorArriba 12         // Aquí decímolle ao arduino que o pin 12 significa motor arriba
#define motorAbaixo 11        //  Aquí decímolle ao arduino que o pin 12 significa motor abaixo
#define pulsador     7        // Aquí decímolle ao arduino que o pin 7 é o pulsador

bool estado = 0;             // Aquí definimos en linguaxe booleano que a palabra estado é 0
int contador = 100;         // Aquí definimos o contador para o numero de impulsos do motor; é un número enteiro


           void setup()               // Aquí configuramos os pins de entradas e saídas
{             
  pinMode(motorArriba, OUTPUT);    // Aquí explicámolle a Arduíno que o pin motor arriba, ou pin 12 é unha saída
  pinMode(motorAbaixo, OUTPUT);   // Aquí explicámolle a Arduíno que o pin motor abaixo, ou pin 11 é unha saída
  pinMode(pulsador, INPUT);       // Aquí explicámolle a Arduíno que o pin pulsador, ou pin 7 é unha entrada
  
  Serial.begin(9600);           // Esta é a velocidade sincronismo das comunicacions
}


          void loop()                          // Esta parte é na que se executa o código "bucle"
{
  
                                      // Inicio lectura do pulsador
  
  
  if(digitalRead(pulsador) {                // Aquí escribimos unha condición (if), na que dicimos " si a lectura dixital (pulsador)" pase as seguintes accións:
    estado = !estado;                      // Ao leer que o pulsador é premido, o estado cambia debido ao simbolo "!", é dicir, cambia o seu valor, neste caso de 0 a 1 ou de 1 a 0
    contador = 100;                       // O contador que vai leer as veces se repite o bucle está en 100 
    while(digitalRead(pulsador)) {        // Mentras que o pulsador é premido, e se lee a súa entrada dixital, o arduíno debe agardar esperando 20 milisegundos
      delay(20);
      }
    }
                                         // Aquí finalizou lectura do "pulsador"
  
  Serial.print("valor do contador: ");       // Esta función (serial.print) serve para que o Arduíno imprima valores, ou o que escriba se vai escrito entre "", neste caso queremos que escriba no monitor "valor do contador" 
  Serial.println(contador);                  // Esta función (serial.println) serve para que o Arduíno inserte un salto de liña e escriba o que poñamos, neste caso o valor "contador", asociado a print.ln que comeza en 100
  Serial.print("  |  Estado: ");            // Aquí xa saltou de liña polo escrito na liña 48; e definimos " | Estado " para que así poña iso literalmente na nova liña
  Serial.println(estado);                  // Aquí atribúe o valor (estado) ao escrito na liña 47, que será 1 ou 0 en función se prememos ou non o botón
   
     
                                        
                                       // Accionamento dos motores
     
  if(contador > 0) {                            // Conta número de impulsos ao motor + aplica a condición "if" (si), o contador é maior ca 0 faga as seguintes instruccións:
    if(estado == 0) {                          // Aplica condición "if" (si); o estado do contador "compara" (==) o valor do estado e en función delo actúa en consecuencia
      digitalWrite(motorArriba, HIGH);         // Indica que a saída dixital "motor arriba" se active (HIGH)
      digitalWrite(motorAbaixo, LOW);          // Indica que a saída dixital "motor abaixo" non se active (LOW); é un enclavamento
      delay(70);                             // Agardamos 70 milisegundos
      contador --;                             // Contador resta unha unidade (contador --;)  ao cumplirse o ciclo descrito anteriormente
 }
    
    
   else {                         // Condición "else" (se non fai isto), no que dicimos que se o estado é diferente ao anterior, realice as seguintes accións:
     
     digitalWrite(motorArriba, LOW);     // Indica que a saída dixital "motor arriba" non se active (LOW)
     digitalWrite(motorAbaixo, HIGH);    // Indica que a saída dixital "motor abaixo" se active (HIGH)
     delay(70);                        // Esperar 70 milisegundos
     contador --;                       // Contador resta unha unidade
   } 
  }
     
  else {                            // Condición "else" (se non fai isto), no que dicimos que se o estado do contador é 0, realice as seguintes accións:   
    
    digitalWrite(motorArriba, LOW);   // Indica que a saída dixital "motor arriba"  non se active (LOW)
    digitalWrite(motorAbaixo,LOW);     // Indica que a saída dixital "motor arriba" non se active (LOW)
   
                      // Fin de accionamento de motores
     }
    
    delay(100);  //Se non está o motor accionado, espera 100 ms ata iniciar o bucle
                  
}
     
     
     
