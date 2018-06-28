
/*
 * http://glslsandbox.com/e#47584.1
 */

#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

#define S(a, b, t) smoothstep(a, b, t)

float N21(vec2 p) {
	return fract(sin(p.x*123.+p.y*3456.)*3524.);
}

vec2 N22(vec2 p) {
	return vec2(N21(p), N21(p+324.));
}

float L(vec2 p, vec2 a, vec2 b) {
	vec2 pa = p-a;
	vec2 ba = b-a;
	
	float t = clamp(dot(pa, ba)/dot(ba, ba), 0., 1.);
	
	float d = length(pa - ba*t);
	
	float m = S(.02, .0, d);
	d = length(a-b);
	float f = S(1., .8, d);
	m *= f;
	m += m*S(.05, .06, abs(d - .75))*2.;
	return m;
}

vec2 GetPos(vec2 p, vec2 o) {
	p += o;
	vec2 n = N22(p)*time;
	p = sin(n)*.4;
	return o+p;
}

float G(vec2 uv) {
	vec2 id = floor(uv);
	uv = fract(uv)-.5;
	
	vec2 g = GetPos(id, vec2(0));
	
	float m = 0.;
	for(float y=-1.; y<=1.; y++) {
		for(float x=-1.; x<=1.; x++) {
			vec2 offs = vec2(x, y);
			vec2 p = GetPos(id, offs);
			
			m+=L(uv, g, p);
			
			vec2 a = p-uv;
			float flash = .003/dot(a, a);
			
			flash *= pow( sin(N21(id+offs)*6.2831+10.*time)*.4+.6, 10.);
			//flash *= pow( sin(time)*.5+.5, 3.);
			m += flash;
		}
	
	}
	
	m += L(uv, GetPos(id, vec2(-1, 0)), GetPos(id, vec2(0, -1)));
	m += L(uv, GetPos(id, vec2(0, -1)), GetPos(id, vec2(1, 0)));
	m += L(uv, GetPos(id, vec2(1, 0)), GetPos(id, vec2(0, 1)));
	m += L(uv, GetPos(id, vec2(0, 1)), GetPos(id, vec2(-1, 0)));
	
	float d = length(g-uv);
	//m = S(.1, .08, d);
	return m;
}

void main( void ) {

	vec2 uv = ( gl_FragCoord.xy-.5*resolution.xy) / resolution.y;

	float d = step(uv.y, 0.);
	
	//if(uv.y<0.)
	//	uv.y = abs(uv.y);
	
	float m = 0.;
	
	m = 0.;
	float t = time*.2;
	for(float i=0.; i<1.; i+=.2) {
		float z = fract(i+t);
		float s = mix(10., .5, z);
		float f = S(0., .4, z)*S(1., .8, z);
		
		m += G(uv*s+100.*i)*f;
	}
	
	t *= 10.;
	vec3 base = .5+sin(vec3(1., .56, .76)*t)*.5;
	vec3 col = base;
	col *= m;
	
	col -= uv.y*base;
	col *= 1.-dot(uv, uv);
	
	//col *= mix(1., .5, d);
	gl_FragColor = vec4( col, 1.0 );

}