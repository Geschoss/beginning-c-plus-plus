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

export const vec3 = (x: number, y: number, z: number): Vec3 => {
    return new Vec3(x, y, z);
};

const length_squared = (v: Vec3) => {
    return v.x * v.x + v.y * v.y + v.z * v.z;
};

export const length = (v: Vec3) => Math.sqrt(length_squared(v));

// Math
export const sum = (u: Vec3, v: Vec3) => {
    return vec3(u.x + v.x, u.y + v.y, u.z + v.z);
};

export const minus = (u: Vec3, v: Vec3) => {
    return vec3(u.x - v.x, u.y - v.y, u.z - v.z);
};

export const multi = (t: number, v: Vec3) => {
    return vec3(t * v.x, t * v.y, t * v.z);
};

export const divided = (v: Vec3, t: number) => {
    return multi(1 / t, v);
};

export const unit_vector = (v: Vec3) => {
    return divided(v, length(v));
};

export class Point3 extends Vec3 {}
export class Color extends Vec3 {}

export const color = (x: number, y: number, z: number) => {
    return new Color(x, y, z);
};

export const point3 = (x: number, y: number, z: number) => {
    return new Point3(x, y, z);
};
