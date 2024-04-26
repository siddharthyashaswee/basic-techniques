/*===========================================================================*/
/*                                                                           *
 * Copyright (c) 2020, Computer Graphics Group RWTH Aachen University        *
 *                            All rights reserved                            *
 *                                                                           *
 * Basic Techniques in Computer Graphics Exercise                            *
 *                                                                           */
/*===========================================================================*/

#include "assignment.hh"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <math.h> 

#define PI 3.14159265


void task::drawScene(int scene, float runTime) { 

	//outer blue circle
	drawCircle(glm::vec3(0.0f, 0.0f, 1.0f), glm::mat4(0.81f, 0.0f,0.0f,0.0f,
								0.0f,0.81f,0.0f,0.0f,
								0.0f,0.0f,1.0f,0.0f,
								0.0f,0.0f,0.0f,1.0f));

	//grey circle
	drawCircle(glm::vec3(0.5f, 0.5f, 0.5f), glm::mat4(0.80f, 0.0f,0.0f,0.0f,
								0.0f,0.80f,0.0f,0.0f,
								0.0f,0.0f,1.0f,0.0f,
								0.0f,0.0f,0.0f,1.0f));
								
	//ellipses for start/stop sign			
	float start=-0.78f;				
	for(int i=0;i<9;i++){
		drawCircle(glm::vec3(1.0f, 1.0f, 1.0f), glm::mat4(0.005f, 0.0f,0.0f,0.0f,
								0.0f,0.03f,0.0f,0.0f,
								0.0f,0.0f,1.0f,0.0f,
								float(start),0.0f,1.0f,1.0f));					
		start= start + 0.02f;
	}	
	
	//inner blue circle			
	drawCircle(glm::vec3(0.0f, 0.0f, 1.0f), glm::mat4(0.6f, 0.0f,0.0f,0.0f,
								0.0f,0.6f,0.0f,0.0f,
								0.0f,0.0f,1.0f,0.0f,
								0.0f,0.0f,0.0f,1.0f));
									
	//inner black circle			
	drawCircle(glm::vec3(0.0f, 0.0f, 0.0f), glm::mat4(0.59f, 0.0f,0.0f,0.0f,
								0.0f,0.59f,0.0f,0.0f,
								0.0f,0.0f,1.0f,0.0f,
								0.0f,0.0f,0.0f,1.0f));
	//spectator stand				
	drawCircle(glm::vec3(0.5f, 0.5f, 0.5f), glm::mat4(0.05f, 0.0f,0.0f,0.0f,
								0.0f,0.5f,0.0f,0.0f,
								0.0f,0.0f,1.0f,0.0f,
								-0.9f,0.0f,1.0f,1.0f));
///------------------------------------------------------------------------------------------------------------------------------------------								
	//divider
	glm::mat4 scale =  glm::mat4(0.03,0,0,0,
						0,0.01,0,0,
						0,0,1,0,
						0,0,0,1);
						
	double angle = 90.0; 
	double tangle = 0.0;
	
	float x = 0.7;
	float y = 0;
	//divider for lower half				
	for(int i=0;i<18;i++){
		
		//std::cout<<"X:"<<x<<" Y:"<<y<<" tangle:"<<tangle<<std::endl;
		glm::mat4 translation = glm::mat4(1,0,0,x,
						0,1,0,y,
						0,0,1,1,
						0,0,0,1);
		
		glm::mat4 rotation =  glm::mat4(cos(angle*PI/180),-sin(angle*PI/180),0,0,
						sin(angle*PI/180),cos(angle*PI/180),0,0,
						0,0,1,0,
						0,0,0,1);
		glm::mat4 myModelMatrix = glm::transpose(translation) * glm::transpose(rotation) * glm::transpose(scale);
		drawCircle(glm::vec3(1.0f, 1.0f, 1.0f), myModelMatrix);
		
		angle -= float(180.0/18.0);
		tangle += float(180.0/18.0);
		x = 0.7*cos(tangle*PI/180);
		y = -1*0.7*sin(tangle*PI/180);
	}
	
	angle = 90.0; 
	tangle = 0.0;
	
	x = 0.7;
	y = 0;
	//divider for upper half				
	for(int i=0;i<18;i++){
		
		//std::cout<<"X:"<<x<<" Y:"<<y<<" tangle:"<<tangle<<std::endl;
		glm::mat4 translation = glm::mat4(1,0,0,x,
						0,1,0,y,
						0,0,1,1,
						0,0,0,1);
		
		glm::mat4 rotation =  glm::mat4(cos(angle*PI/180),-sin(angle*PI/180),0,0,
						sin(angle*PI/180),cos(angle*PI/180),0,0,
						0,0,1,0,
						0,0,0,1);
		glm::mat4 myModelMatrix = glm::transpose(translation) * glm::transpose(rotation) * glm::transpose(scale);
		drawCircle(glm::vec3(1.0f, 1.0f, 1.0f), myModelMatrix);
		
		angle += float(180.0/18.0);
		tangle += float(180.0/18.0);
		x = 0.7*cos(tangle*PI/180);
		y = 0.7*sin(tangle*PI/180);
	}
//-----------------------------------------------------------------------------------------------------------------------------------------
	//inner car - yellow
	glm::mat4 scaleYellow =  glm::mat4(0.02,0,0,0,
						0,0.08,0,0,
						0,0,1,0,
						0,0,0,1);
						
	glm::mat4 myModelMatrix = glm::mat4(1.);					
	
	float pathRadius = 0.65;
	glm::mat4 translation = glm::mat4(1,0,0,pathRadius*cos((-1*20*runTime-180)*PI/180),
						0,1,0,pathRadius*sin((-1*20*runTime-180)*PI/180),
						0,0,1,1,
						0,0,0,1);
		
	glm::mat4 rotation =  glm::mat4(cos((-1*20*runTime-180)*PI/180),-sin((-1*20*runTime-180)*PI/180),0,0,
						sin((-1*20*runTime-180)*PI/180),cos((-1*20*runTime-180)*PI/180),0,0,
						0,0,1,0,
						0,0,0,1);
						
	myModelMatrix = glm::transpose(translation) * glm::transpose(rotation) * glm::transpose(scaleYellow);
        		drawCircle(glm::vec3(1.0f, 1.1f, 0.0f), myModelMatrix);  
	             
//-----------------------------------------------------------------------------------------------------------------------------------------
	//outer car - green
	// glColor3f(0.0f, 0.99f, 0.0f); // rgb green
	glm::mat4 scaleGreen =  	glm::mat4(0.02,0,0,0,
						0,0.08,0,0,
						0,0,1,0,
						0,0,0,1);
						
	float pathRadiusG = 0.75;
	glm::mat4 translationGreen = glm::mat4(1,0,0,pathRadiusG*cos((-1*40*runTime-180)*PI/180),
						0,1,0,pathRadiusG*sin((-1*40*runTime-180)*PI/180),
						0,0,1,1,
						0,0,0,1);
		
	glm::mat4 rotationGreen =  glm::mat4(cos((-1*40*runTime-180)*PI/180),-sin((-1*40*runTime-180)*PI/180),0,0,
						sin((-1*40*runTime-180)*PI/180),cos((-1*40*runTime-180)*PI/180),0,0,
						0,0,1,0,
						0,0,0,1);
						
	myModelMatrix = glm::transpose(translationGreen) * glm::transpose(rotationGreen) * glm::transpose(scaleGreen);
        		drawCircle(glm::vec3(0.0f, 0.99f, 0.0f), myModelMatrix);
		
}
void task::initCustomResources() {}
void task::deleteCustomResources() {}
