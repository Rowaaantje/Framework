/*
* Copyright Rowan Pijnaker
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
	
private:

};

#endif /* CONFIG_H */
