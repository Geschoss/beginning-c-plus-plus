import { Log } from './std';
import { Vec3 } from './vec3';

export const wrire_color = (log: Log, pixel: Vec3) => {
    const ir = Math.floor(255.999 * pixel.x);
    const ig = Math.floor(255.999 * pixel.y);
    const ib = Math.floor(255.999 * pixel.z);

    log(`${ir} ${ig} ${ib}`);
};
