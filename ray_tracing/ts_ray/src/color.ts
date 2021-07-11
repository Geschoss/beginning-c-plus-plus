import { at, Ray } from './ray';
import { Log } from './std';
import {
    dot,
    sum,
    minus,
    multi,
    point3,
    Vec3,
    color,
    Color,
    Point3,
    unit_vector,
    divided,
    vec3,
    length_squared,
} from './vec';

// Colors
const white = color(1.0, 1.0, 1.0);
const blue = color(0.5, 0.7, 1.0);
const red = color(1, 0, 0);

// “linear blend”, or “linear interpolation
const lerp = (t: number, start: Color, end: Color) =>
    sum(multi(1.0 - t, start), multi(t, end));

const hit_sphere = (
    center: Point3,
    radius: number,
    r: Ray
) => {
    const oc = minus(r.orig, center);

    const a = length_squared(r.dir);
    const half_b = dot(oc, r.dir);
    const c = minus(
        length_squared(oc),
        multi(radius, radius)
    );

    const discriminant = minus(
        multi(half_b, half_b),
        multi(a, c)
    );

    if (discriminant < 0) {
        return -1;
    } else {
        return divided(
            minus(-half_b, Math.sqrt(discriminant)),
            a
        );
    }
};

const negative_vec = vec3(0, 0, -1);

export const ray_color = (r: Ray) => {
    let t = hit_sphere(point3(0, 0, -1), 0.5, r);

    if (t > 0.0) {
        const N = unit_vector(
            minus(at(r, t), negative_vec)
        );

        return multi(0.5, color(N.x + 1, N.y + 1, N.z + 1));
    }

    const unit_diraction = unit_vector(r.dir);

    t = 0.5 * (unit_diraction.x + 1);

    return lerp(t, white, blue);
};

export const wrire_color = (log: Log, pixel: Vec3) => {
    const ir = Math.floor(255.999 * pixel.x);
    const ig = Math.floor(255.999 * pixel.y);
    const ib = Math.floor(255.999 * pixel.z);

    log(`${ir} ${ig} ${ib}`);
};
