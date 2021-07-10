export const log = (msg: any) => {
    console.log(`${msg}`);
};

export type Log = typeof log;

export const processLog = (j: number) => {
    process.stderr.clearLine(0);
    process.stderr.cursorTo(0);
    process.stderr.write(`Scanlines remaining: ${j}`);
};

export type ProcessLog = typeof processLog;
