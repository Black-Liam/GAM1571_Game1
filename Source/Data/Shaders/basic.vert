#version 100

attribute vec2 a_Position;

void main()
{
	a_Position /= 20.0;
    gl_Position = vec4( a_Position, 0, 1 );
}