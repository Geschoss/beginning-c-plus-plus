import { vec3, Vec3 } from './vec3';

// Math
function sum(u: Vec3, v: Vec3): Vec3;
function sum(u: number, v: number): number;
function sum(u: any, v: any): any {
    if (v instanceof Vec3 && u instanceof Vec3) {
        return vec3(u.x + v.x, u.y + v.y, u.z + v.z);
    } else if (
        typeof v === 'number' &&
        typeof u === 'number'
    ) {
        return u + v;
    }

    throw new Error('Miss type');
}

function minus(t: Vec3, v: Vec3): Vec3;
function minus(t: number, v: number): number;
function minus(u: any, v: any): any {
    if (v instanceof Vec3 && u instanceof Vec3) {
        return vec3(u.x - v.x, u.y - v.y, u.z - v.z);
    } else if (
        typeof v === 'number' &&
        typeof u === 'number'
    ) {
        return u - v;
    }

    throw new Error('Miss type');
}

function multi(t: number, v: Vec3): Vec3;
function multi(t: number, v: number): number;
function multi(t: any, v: any): any {
    if (v instanceof Vec3 && typeof t === 'number') {
        return vec3(t * v.x, t * v.y, t * v.z);
    } else if (
        typeof v === 'number' &&
        typeof t === 'number'
    ) {
        return t * v;
    }

    throw new Error('Miss type');
}
function divided(v: Vec3, t: number): Vec3;
function divided(v: number, t: number): number;
function divided(v: any, t: any): any {
    if (v instanceof Vec3 && typeof t === 'number') {
        return multi(1 / t, v);
    } else if (
        typeof v === 'number' &&
        typeof t === 'number'
    ) {
        return v / t;
    }

    throw new Error('Miss type');
}

const dot = (u: Vec3, v: Vec3) =>
    u.x * v.x + u.y * v.y + u.z * v.z;

const length_squared = (v: Vec3) =>
    v.x * v.x + v.y * v.y + v.z * v.z;

const length = (v: Vec3) => Math.sqrt(length_squared(v));

const unit_vector = (v: Vec3) => divided(v, length(v));

export {
    dot,
    sum,
    multi,
    minus,
    length,
    divided,
    unit_vector,
    length_squared,
};
