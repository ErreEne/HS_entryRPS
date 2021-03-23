
int LED1 = 2;
int LED2 = 5;
int LED3 = 7;

int binit = 11;
int btesoura = 8;
int bpapel = 12;
int bpedra = 9;

int vini = 0;
int vtesoura = 0;
int vpapel = 0;
int vpedra = 0;

int jogada1;
int jogada2;

void setup()
{
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(binit, INPUT);
	pinMode(btesoura, INPUT);
	pinMode(bpapel, INPUT);
	pinMode(bpedra, INPUT);
}

void loop()
{

	//Estado a mostrar que o arduino está ligado
	digitalWrite(LED1, HIGH);
	digitalWrite(LED2, HIGH);
	digitalWrite(LED3, HIGH);

	//Definir os botões
	vini = digitalRead(binit);

	if ( vini == 1){

		//reset no botão
		delay(1000);
		vini = 0;
		//Sinal que o jogo começou
		digitalWrite(LED1, LOW);
		digitalWrite(LED2, LOW);
		digitalWrite(LED3, LOW);
		delay (1000);

		digitalWrite(LED1, HIGH);
		delay(500);
		digitalWrite(LED2, HIGH);
		delay(500);
		digitalWrite(LED3, HIGH);
		delay(500);
		delay(1000)
		;
		int player1 = 0;
		int player2 = 0;

		//Escolher o modo "singleplayer" ou "multiplayer"
		while( player1<1 && player2<1){

			player1 = digitalRead(btesoura);
			player2 = digitalRead(binit);
		}

		digitalWrite(LED1, LOW);
		digitalWrite(LED2, LOW);
		digitalWrite(LED3, LOW);
		delay(1000);

		digitalWrite(LED1, HIGH);
		delay(500);
		digitalWrite(LED2, HIGH);
		delay(500);
		digitalWrite(LED3, HIGH);
		delay(1500);

			if(player2 == 1){

				jogador1();
				jogador2();
				resultado();	

			}else if(player1 == 1){

				jogador1();
				jogada2 = random(1, 3);
				if( jogada2 == 1){
					digitalWrite(LED1, LOW);
					delay(1000);
					digitalWrite(LED1, HIGH);
				}else if(jogada2 == 2){
					digitalWrite(LED2, LOW);
					delay(1000);
					digitalWrite(LED2, HIGH);
				}else if( jogada2 == 3){
					digitalWrite(LED3, LOW);
					delay(1000);
					digitalWrite(LED3, HIGH);
				}
				resultado();
			}	
	}else{	}

}
//Função do jogador 1
void jogador1(){
	//Esperar a jogada
	while(vtesoura<1 && vpapel<1 && vpedra<1){
		vtesoura = digitalRead(btesoura);
		vpedra = digitalRead(bpedra);
		vpapel = digitalRead(bpapel);
	}
	if(vtesoura == 1){

		digitalWrite(LED1, LOW);
		delay(2000);
		digitalWrite(LED1, HIGH);
		jogada1 = 1;
		vtesoura = vtesoura - 1;
		delay(1000);
	}else if(vpapel == 1){

		digitalWrite(LED2, LOW);
		delay(2000);
		digitalWrite(LED2, HIGH);
		jogada1 = 2;
		vpapel = vpapel - 1;
		delay(1000);

	}else if(vpedra == 1){

		digitalWrite(LED3, LOW);
		delay(2000);
		digitalWrite(LED3, HIGH);
		jogada1 = 3;
		vpedra = vpedra - 1;
		delay(1000);
	}
}
//Função do jogador2
void jogador2(){
	//Esperar a jogada
	while(vtesoura<1 && vpapel<1 && vpedra<1){
		vtesoura = digitalRead(btesoura);
		vpedra = digitalRead(bpedra);
		vpapel = digitalRead(bpapel);
	}
	if(vtesoura == 1){

		digitalWrite(LED1, LOW);
		delay(2000);
		digitalWrite(LED1, HIGH);
		jogada2 = 1;
		vtesoura = vtesoura - 1;
		delay(1000);

	}else if(vpapel == 1){

		digitalWrite(LED2, LOW);
		delay(2000);
		digitalWrite(LED2, HIGH);
		jogada2 = 2;
		vpapel = vpapel - 1;
		delay(1000);

	}else if(vpedra == 1){

		digitalWrite(LED3, LOW);
		delay(2000);
		digitalWrite(LED3, HIGH);
		jogada2 = 3;
		vpedra = vpedra - 1;
		delay(1000);
	}	
}

void resultado(){

	if(jogada1 == jogada2){

		digitalWrite(LED1, LOW);
		digitalWrite(LED3, LOW);
		delay(10000);
		//Empate
	}else if( (jogada1 == 3 && jogada2 == 1) || (jogada1 == 1 && jogada2 == 2) || (jogada1 == 2 && jogada2 == 3)){

		digitalWrite(LED1, LOW);
		delay(2000);
		//Vitoria1
	}else if( (jogada2 == 3 && jogada1 == 1) || (jogada2 == 1 && jogada1 == 2) || (jogada2 == 2 && jogada1 == 3)){

		digitalWrite(LED3, LOW);
		delay(2000);
		//Vitoria2

	}
}