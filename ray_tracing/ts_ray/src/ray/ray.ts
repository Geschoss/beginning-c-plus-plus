import { sum, multi, Vec3, Point3 } from '../vec';

export class Ray {
    readonly orig: Point3;
    readonly dir: Vec3;

    constructor(origin: Point3, direction: Vec3) {
        this.orig = new Point3(
            origin.x,
            origin.y,
            origin.z
        );
        this.dir = new Vec3(
            direction.x,
            direction.y,
            direction.z
        );
    }
}

export const ray = (origin: Point3, direction: Vec3) =>
    new Ray(origin, direction);

export const at = (r: Ray, t: number) =>
    sum(r.orig, multi(t, r.dir));
