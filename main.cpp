int inputPins[] = {8,9,10,11,12};
int length = sizeof(inputPins)/sizeof(int);
int timeDelay = 300;

void setup()
{
	for(int i = 0;i<length;i++)
	{
		pinMode(inputPins[i],OUTPUT);
	}
	randomSeed(analogRead(0));
}

void loop()
{
	// Fisher-Yates Shuffle
	for(int i = length-1;i>=1;i--)
	{
		int j = random(0,i+1);
		int temp = inputPins[j];
		inputPins[j] = inputPins[i];
		inputPins[i] = temp; 
	}
	
	for(int i = 0;i<length;i++)
	{
		digitalWrite(inputPins[i],HIGH);
		delay(timeDelay);
		digitalWrite(inputPins[i],LOW);
	}
}