import { Color, color, multi, Point3, sum, unit_vector, Vec3 } from './vec3';

export class Ray {
    orig: Point3;
    dir: Vec3;

    constructor(origin: Point3, direction: Vec3) {
        this.orig = new Point3(origin.x, origin.y, origin.z);
        this.dir = new Vec3(direction.x, direction.y, direction.z);
    }
}

export const ray = (origin: Point3, direction: Vec3) => {
    return new Ray(origin, direction);
};

export const at = (r: Ray, t: number) => {
    return sum(r.orig, multi(t, r.dir));
};

// “linear blend”, or “linear interpolation
const lerp = (t: number, start: Color, end: Color) =>
    sum(multi(1.0 - t, start), multi(t, end));

const white = color(1.0, 1.0, 1.0);
const blue = color(0.5, 0.7, 1.0);

export const ray_color = (r: Ray) => {
    const unit_diraction = unit_vector(r.dir);
    const t = 0.5 * (unit_diraction.x + 1);

    return lerp(t, white, blue);
};
