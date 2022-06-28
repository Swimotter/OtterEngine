#pragma once

namespace otterMath {
	enum qualifier {
		packed_highp,
		packed_mediump,
		packed_lowp,

		highp = packed_highp,
		mediump = packed_mediump,
		lowp = packed_lowp,
		packed = packed_highp,
	};
}