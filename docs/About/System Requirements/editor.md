---
title: Grace Editor
nav_order: 1
parent: System Requirements
---

# Grace Editor - System Requirements

This page contains the system requirements for the GraceEngine editor. These specifications are to be used as a guide to help users build or upgrade their computer. Please not this is only a guide, performance may vary with newer versions of GraceEngine however performance testing will be carried out occasionally for every few patches.

### Desktop or Laptop - Minimum

| Hardware         | Requirement                                                                                                                                                                                                                                                                                                                                                                 |
|------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| CPU              | <html><ul><li>Windows: x86_64 or ARMv8 CPU<ul><li>Example: x64: (Intel i3-4005u, AMD A6-7310) ARM: (Snapdragon X X1)</li></ul></li><li>MacOS: x86_64 or ARM CPU<ul><li>Example: x64 (i5-3317u) ARM: (Apple M1)</li></ul></li><li>Linux: x86_64 or ARMv8 CPU<ul><li>Example: x64: (Intel i3-4005u, AMD A6-7310) ARM: (Raspberry Pi 4B - BCM 2711)</li></ul></li></ul></html> |
| GPU              | <ul><li>Integrated graphics with OpenGL 3.0+ support <ul><li>Example: Intel HD 4000, Radeon R4 graphics, VideoCore VI</li></ul></li></ul>                                                                                                                                                                                                                                   |
| RAM              | 4GB                                                                                                                                                                                                                                                                                                                                                                         |
| Storage          | 30MB (used by GraceEngine libraries). After building project 250MB (used for GraceEngine, SFML, and a simple project).                                                                                                                                                                                                                                                      |
| Operating System | <ul><li>Windows: 10 or later[^1]</li><li>Linux: 2017 distro or later</li><li>MacOS: 10.14 or later</li></ul>                                                                                                                                                                                                                                                                |

<table>
  <thead>
    <tr>
      <th>Hardware</th>
      <th>Requirement</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>CPU</td>
      <td>
        <ul>
          <li>Windows: x86_64 or ARMv8 CPU
            <ul>
              <li>Example: x64: (Intel i3-4005u, AMD A6-7310), ARM: (Snapdragon X X1)</li>
            </ul>
          </li>
          <li>MacOS: x86_64 or ARM CPU
            <ul>
              <li>Example: x64: (i5-3317u), ARM: (Apple M1)</li>
            </ul>
          </li>
          <li>Linux: x86_64 or ARMv8 CPU
            <ul>
              <li>Example: x64: (Intel i3-4005u, AMD A6-7310), ARM: (Raspberry Pi 4B - BCM 2711)</li>
            </ul>
          </li>
        </ul>
      </td>
    </tr>
    <tr>
      <td>GPU</td>
      <td>
        <ul>
          <li>Integrated graphics with OpenGL 3.0+ support
            <ul>
              <li>Example: Intel HD 4000, Radeon R4 graphics, VideoCore VI</li>
            </ul>
          </li>
        </ul>
      </td>
    </tr>
    <tr>
      <td>RAM</td>
      <td>4GB</td>
    </tr>
    <tr>
      <td>Storage</td>
      <td>30MB (GraceEngine libraries). After build: ~250MB (GraceEngine, SFML, and a simple project).</td>
    </tr>
    <tr>
      <td>Operating System</td>
      <td>
        <ul>
          <li>Windows: 10 or later[^1]</li>
          <li>Linux: 2017 distro or later</li>
          <li>MacOS: 10.14 or later</li>
        </ul>
      </td>
    </tr>
  </tbody>
</table>


{: .important }
> Theoretically GraceEngine will compile on macOS, it has not been tested.

[^1]: Previous versions of Windows are untested. MSYS2 requires Windows 10 or later while VS2017 does support Windows 7 with SP1. However, we do not recommend using it due to the lack of security updates.