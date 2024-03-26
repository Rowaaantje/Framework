/*
* Copyright 2024 Rowan Pijnaker
*/

#ifndef CONFIG_H
#define CONFIG_H

class Config 
{
public:
	Config();
	virtual ~Config();
	virtual void update(float deltaTime);
	
	#define SCREEN_WIDTH  800
	#define SCREEN_HEIGHT  800
	#define WINDOWNAME "Test"

	#define SEMI_TRANSPARENT_BLACK CLITERAL(Color){ 0, 0, 0, 50 }
	#define INVINSIBLE CLITERAL(Color){ 0, 0, 0, 0 }
	
private:

};

#endif /* CONFIG_H */
