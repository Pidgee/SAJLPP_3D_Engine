#version 120

varying vec4 globalColor;

// the time value is passed into the shader by the OF app.
uniform float time;

void main()
{
    vec4 position = ftransform();
    
    float displacementWidth = 150.0;
    float displacementHeight = 100.0;
    float displacementX = cos(time + (position.y / 100.0)) * displacementWidth;
    float displacementY = sin(time + (position.x / 100.0)) * displacementHeight;
    
    vec4 modifiedPosition = position;
        
	modifiedPosition.y += displacementY;
	modifiedPosition.x -= displacementX;
	gl_Position = modifiedPosition;
    
    
    globalColor = gl_Color;
}