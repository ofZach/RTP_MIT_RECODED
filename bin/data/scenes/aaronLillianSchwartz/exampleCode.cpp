shader.begin();

color = vec3(
             [[speedParticles]]*sin(time),
             sin([[speedColor]]*time),
             0.3);

shader.end();
