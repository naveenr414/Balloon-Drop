int inputPins[] = {8,7,6,5,4};
int length = sizeof(inputPins)/sizeof(int);
int speed = 255;
int timeDelay = 1000;

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
		analogWrite(inputPins[i],speed);
		delay(timeDelay);
		analogWrite(inputPins[i],0);
	}
}