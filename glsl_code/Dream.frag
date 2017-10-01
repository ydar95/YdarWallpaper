
#ifdef GL_ES

precision mediump float;

#endif

 

#ifndef REDUCER

#define _GLF_ZERO(X, Y)          (Y)

#define _GLF_ONE(X, Y)           (Y)

#define _GLF_FALSE(X, Y)         (Y)

#define _GLF_TRUE(X, Y)          (Y)

#define _GLF_IDENTITY(X, Y)      (Y)

#define _GLF_DEAD(X)             (X)

#define _GLF_FUZZED(X)           (X)

#define _GLF_WRAPPED_LOOP(X)     X

#define _GLF_WRAPPED_IF_TRUE(X)  X

#define _GLF_WRAPPED_IF_FALSE(X) X

#endif

 

uniform float time;

uniform vec2 resolution;

 

void main(void)

{

    vec2 uv = gl_FragCoord.xy / resolution.xy - .5;

    uv.y *= resolution.y / resolution.x;

    vec3 dir = vec3(uv * 0.7, 1.2);

    float a2 = time * 20. + .5;

    float a1 = 0.0;

    mat2 rot1 = mat2(cos(a1), sin(a1), - sin(a1), cos(a1));

    mat2 rot2 = rot1;

    dir.xz *= rot1;

    dir.xy *= rot2;

    vec3 from = vec3(0., 0., 0.);

    from += vec3(.025 * time, .03 * time, - 2.);

    from.xz *= rot1;

    from.xy *= rot2;

    float s = .1, fade = .07;

    vec3 v = vec3(0.4);

    for(

        int r = 0;

        r < 12;

        r ++

    )

        {

		float my_scale = 1.;

            vec3 p = from + s * dir * my_scale;

            p = abs(vec3(0.750) - mod(p, vec3(0.750 * 2.)));

            p.x += float(r * r) * 0.01;

            p.y += float(r) * 0.02;

            float pa, a = pa = 0.;

            for(

                int i = 0;

                i < 15;

                i ++

            )

                {

                    p = abs(p) / dot(p, p) - 0.340;

                    a += abs(length(p) - pa * 0.2);

                    pa = length(p);

                }

            a *= a * a * 4.;

            v += vec3(s, s * s, s * s * s * s) * a * 0.0017 * fade;

            fade *= 0.960;

            s += 0.120;

        }

    v = mix(vec3(length(v)), v, 0.8);

    gl_FragColor = vec4(v * .01, 1.);

}

