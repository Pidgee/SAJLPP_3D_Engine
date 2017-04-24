#version 150

uniform mat4 modelViewProjectionMatrix;
in vec4 position;

uniform float time;

void main()
{

    float displacementWidth = 150.0;
    float displacementHeight = 100.0;
    float displacementX = sin(time + (position.y / 100.0)) * displacementWidth;
    float displacementY = sin(time + (position.x / 100.0)) * displacementHeight;
    
    vec4 modifiedPosition = modelViewProjectionMatrix * position;
        
	modifiedPosition.y += displacementY;
	modifiedPosition.x -= displacementX;
	gl_Position = modifiedPosition;
    
}