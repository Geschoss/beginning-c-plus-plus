import { wrire_color } from './color';
import { ray, ray_color } from './ray';
import { log, processLog } from './std';
import { divided, minus, multi, point3, sum, vec3 } from './vec3';

(() => {
    // Image
    const aspect_ration = 16.0 / 9.0;
    const image_width = 400;
    const image_height = Math.floor(image_width / aspect_ration);

    // Camera
    const viewport_height = 2.0;
    const viewport_width = aspect_ration * viewport_height;
    const focal_length = 1.0;

    const origin = point3(0, 0, 0);
    const horizontal = vec3(viewport_width, 0, 0);
    const vertical = vec3(0, viewport_height, 0);
    const lower_left_corner = minus(
        minus(minus(origin, divided(horizontal, 2)), divided(vertical, 2)),
        vec3(0, 0, focal_length)
    );

    log(`P3\n${image_width} ${image_height}\n255`);

    for (let j = image_height - 1; j >= 0; j--) {
        processLog(j);
        for (let i = 0; i < image_width; i++) {
            const u = i / (image_width - 1);
            const v = j / (image_height - 1);

            const direction = minus(
                sum(
                    sum(lower_left_corner, multi(u, horizontal)),
                    multi(v, vertical)
                ),
                origin
            );
            const r = ray(origin, direction);
            const pixel_color = ray_color(r);

            wrire_color(log, pixel_color);
        }
    }
})();
