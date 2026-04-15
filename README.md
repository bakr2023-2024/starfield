# Starfield

An ambient starfield simulation with perspective projection and depth trails. Best experienced fullscreen with the lights off.

## Requirements

- The executable `starfield.exe`
- The music file `let-it-happen.mp3` in the same directory as the executable
  - Song: [Let It Happen (slowed + pitched down) — Tame Impala](https://www.youtube.com/watch?v=vWeAJmvE_xY)

## Running

Basic usage:

```
./starfield.exe
```

With custom options:

```
./starfield.exe <stars> <fps> <space color> <stars color>
```

All arguments are optional and positional — you must provide the earlier ones to set the later ones.

| Argument      | Default      | Description                  |
| ------------- | ------------ | ---------------------------- |
| `stars`       | `18000`      | Number of stars              |
| `fps`         | `90`         | Target framerate             |
| `space color` | `0x000000FF` | Background color in RGBA hex |
| `stars color` | `0xFFFFFFFF` | Star color in RGBA hex       |

### Examples

```
./starfield.exe
./starfield.exe 18000
./starfield.exe 18000 90
./starfield.exe 18000 90 0x000000FF
./starfield.exe 18000 90 0x000000FF 0xFF69B4FF
```

## Controls

| Input            | Action                |
| ---------------- | --------------------- |
| Mouse wheel up   | Increase speed        |
| Mouse wheel down | Decrease speed        |
| Arrow up         | Increase music volume |
| Arrow down       | Decrease music volume |

## Colors

Colors are specified as 8-digit RGBA hexadecimal values in the format `0xRRGGBBFF` where the last two digits are opacity (always use `FF` for fully opaque).

| Color | Hex          |
| ----- | ------------ |
| Black | `0x000000FF` |
| White | `0xFFFFFFFF` |
| Red   | `0xFF0000FF` |
| Pink  | `0xFF69B4FF` |
| Blue  | `0x0000FFFF` |
| Green | `0x00FF00FF` |
