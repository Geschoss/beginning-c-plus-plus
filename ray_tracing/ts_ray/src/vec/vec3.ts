export class Vec3 {
    readonly x: number;
    readonly y: number;
    readonly z: number;
    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    toString() {
        return `${this.x} ${this.y} ${this.z}`;
    }
}

export const vec3 = (
    x: number,
    y: number,
    z: number
): Vec3 => new Vec3(x, y, z);

// RGB color
export class Color extends Vec3 {}
export const color = (x: number, y: number, z: number) =>
    new Color(x, y, z);

// 3D point
export class Point3 extends Vec3 {}
export const point3 = (x: number, y: number, z: number) =>
    new Point3(x, y, z);
