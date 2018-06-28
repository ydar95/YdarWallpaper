#ifdef GL_ES
precision mediump float;
#endif
// mods by dist, shrunk slightly by @danbri

precision mediump float;
uniform float time;
uniform vec2 mouse, resolution;
void main(void) {
	vec2 uPos = ( gl_FragCoord.xy / resolution.xy );//normalize wrt y axis
	uPos -= .5;
	vec3 color = vec3(0.0);
	for( float i = 0.; i <20.; ++i ) {
		uPos.y += sin( uPos.x*(i) + (time * i * i * .1) ) * 0.15;
		float fTemp = abs(1.0 / uPos.y / 500.0);
		//vertColor += fTemp;
		color += vec3( fTemp*(8.0-i)/7.0, fTemp*i/10.0, pow(fTemp,1.0)*1.5 );
	}
	gl_FragColor = vec4(color, 10.0);
}