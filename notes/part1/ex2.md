# Exercise 2

> Why do you think the distinction between code and data sections exists?

Probably because it would become a huge mess and finding values would be resource-intensive.

> How do you think the loading process differs for code and data sections?

The `code` section should be loaded immediately, while the `data` one later.

> Is it necessary to copy all sections into memory when a binary is loaded for execution?

Probably not.