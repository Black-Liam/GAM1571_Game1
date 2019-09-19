#version 120

uniform float u_Timer;
varying vec4 v_Color;

void main()
{
	gl_FragColor = v_Color * u_Timer;
}