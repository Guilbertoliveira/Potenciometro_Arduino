int valor = 0; //variavel que ira receber o valor convertido da porta analogica
int led = 11; // valor da porta digital essa porta necessita ter o ~
int potenciometro = A0; // valor da porta do potenciometro analogico
int valorpwm = 0;
int valoranalogico = 0;


void setup() {

 Serial.begin(9600); // padrao para demonstrar no monitor os valores que estao sendo exibidos, abrindo a conexao entre o monitor e o arduino
 
}

void loop() {
 
  valoranalogico = analogRead(A0); // com o analogRead(portaanalogica), conseguimos converter de 0 - 5V em 0 - 1023 (padrao analogico)
  valorpwm = map(valoranalogico, 0, 1023, 0, 255); // a funcao map recebe 5 parametros (valordeentrada, min_entrada, max_entrada, min_saida, max_saida), Remapeia um número de um intervalo para outro
  analogWrite(led, valorpwm); // led (é o numero do pinto que recebera o sinal de saida), valor (é a razao ciclica um valor de 0 a 255), com essa função o arduino ja sabe que é uma saida não necessitando de pinmode

// print no console para entender a diferença 
  Serial.print("valor analogico = " );    // com essa comparação conseguimos perceber a diferença da analogica e digital no console                   
  Serial.print(valoranalogico);      
  Serial.print("\t valor digital = ");      
  Serial.println(valorpwm);   

  
  


}
