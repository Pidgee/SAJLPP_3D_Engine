#version 120

void main()
{
    float windowWidth = 1024.0;
    float windowHeight = 768.0;
    
	float r = sin(float(gl_FragCoord.x)/10);
	float g = sin(float(gl_FragCoord.y)/10);
	float b = 1.0;
	float a = 1.0;
	gl_FragColor = vec4(r, g, b, a);
}
